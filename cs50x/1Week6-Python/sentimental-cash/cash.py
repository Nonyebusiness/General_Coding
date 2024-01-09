def main():
    while True:
        try:
            dollar = float(input("Change owed: "))
            if dollar >= 0:
                break
            print("please give a positive number")
        except ValueError:
            print("please give a number")

    cents = round(dollar * 100)

    quarters = cents // 25
    cents -= quarters * 25

    dimes = cents // 10
    cents -= dimes * 10

    nickels = cents // 5
    cents -= nickels * 5

    pennies = cents // 1

    total_coins = quarters + dimes + nickels + pennies

    print(total_coins)

main()
