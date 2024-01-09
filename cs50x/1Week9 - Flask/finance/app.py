import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response



@app.route("/")
@login_required
def index():

    """Show portfolio of stocks"""
    user_id = session["user_id"]

    stocks = db.execute("""
        SELECT symbol, shares
        FROM portfolio
        WHERE user_id = :user_id
        AND shares > 0
    """, user_id=user_id)

    cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=user_id)[0]["cash"]

    total_value = cash

    for stock in stocks:
        quote_info = lookup(stock["symbol"])
        if quote_info is not None:
            stock["price"] = quote_info["price"]
            stock["total_value"] = stock["shares"] * stock["price"]
            total_value += stock["total_value"]

    return render_template("index.html", stocks=stocks, cash_balance=cash, total_value=total_value)





@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not shares.isdigit() or int(shares) <= 0:
            return apology("Shares must be a positive integer")
        quote_info = lookup(symbol)

        if quote_info is None:
            return apology("Invalid stock symbol")

        price = quote_info['price']

        total_cost = int(shares) * price

        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        if user_cash < total_cost:
            return apology("Can't Afford")
        new_cash = user_cash - total_cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session["user_id"])

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
           session["user_id"], symbol, shares, price)


        user_id = session["user_id"]
        stock_in_portfolio = db.execute("SELECT * FROM portfolio WHERE user_id = ? AND symbol = ?", user_id, symbol)

        if not stock_in_portfolio:
            db.execute("INSERT INTO portfolio (user_id, symbol, shares) VALUES (?, ?, ?)", user_id, symbol, shares)
        else:
            current_shares = stock_in_portfolio[0]["shares"]
            new_shares = current_shares + int(shares)
            db.execute("UPDATE portfolio SET shares = ? WHERE user_id = ? AND symbol = ?", new_shares, user_id, symbol)

        flash("Bought!")
        return redirect("/")

    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]

    transactions = db.execute("SELECT * FROM transactions WHERE user_id = :user_id", user_id=user_id)

    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        quote_info = lookup(symbol)

        if quote_info is None:
            return apology("Passwords do not match")

        return render_template("quoted.html", quote_info=quote_info)
    else:
        return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        retype_password = request.form.get("confirmation")

        if not username or not password or not retype_password:
            return apology("Fill all forms")

        if password != retype_password:
            return apology("Passwords do not match")

        # Check if the username already exists
        taken_name = db.execute("SELECT * FROM users WHERE username = ?", username)

        if len(taken_name) != 0:
            return apology("Username already exists")

        if not any(char.isdigit() for char in password) or not any(char.isalnum() for char in password):
            return apology("Password must contain at least one number and one symbol")

        # Hash the password
        hash_password = generate_password_hash(password)

        # Insert the new user into the database
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash_password)

        # Log in the user
        user = db.execute("SELECT * FROM users WHERE username = ?", username)

        session["user_id"] = user[0]["id"]
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session["user_id"]

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares_to_sell = int(request.form.get("shares"))


        if not symbol or shares_to_sell is None or shares_to_sell <= 0:
            return apology("Please provide valid symbol and number of shares", 400)


        owned_stocks = db.execute("SELECT symbol, shares FROM portfolio WHERE user_id = ? AND shares > 0", user_id)

        if not owned_stocks:
            return apology("You don't own any shares of this stock", 400)


        if shares_to_sell > owned_stocks[0]["shares"]:
            return apology("You don't have enough shares to sell", 400)


        quote_info = lookup(symbol)

        if not quote_info:
            return apology("Invalid symbol", 400)

        current_price = quote_info["price"]

        total_value = shares_to_sell * current_price

        db.execute("UPDATE portfolio SET shares = shares - ? WHERE user_id = ? AND symbol = ?", shares_to_sell, user_id, symbol)

        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total_value, user_id)

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
                   user_id, symbol, -shares_to_sell, current_price)

        flash("Sold")
        return redirect("/")

    else:
        owned_stocks = db.execute("SELECT symbol FROM portfolio WHERE user_id = ? AND shares > 0", user_id)
        return render_template("sell.html", stocks=owned_stocks)
