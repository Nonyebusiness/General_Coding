import matplotlib.pyplot as plt

class Expense:
    def __init__(self, name, how_often, price):
        self.name = name
        self.how_often = how_often
        self.price = price

try:
    num_expense = int(input("How many money flows do you want to add?: "))
except ValueError:
    print("Enter Valid Input.")
    num_expense = 0

try:
    graph_length = int(input("How far do you want to see?: "))
except ValueError:
    print("Enter Valid Input.")
    graph_length = 0 

expense = []

for i in range(num_expense):
    try:
        name = input("Name: ")
        period = int(input("How often: "))
        price = int(input("Cost: "))
    except ValueError:
        print("Enter valid input.")
        continue
    
    expense.append(Expense(name, period, price))

x_values = list(range(1, graph_length + 1))
y_values = [0] * graph_length
current_value = 0 

# Iterate through each x value
for x in x_values:
    # Check if there's any change in expenses at the current x value
    changes = [individual_expense.price for individual_expense in expense if x % individual_expense.how_often == 0]
    
    if changes:
        # Update the y value based on the current expenses
        current_value += sum(changes)
    
    y_values[x - 1] = current_value

# Plot the graph
plt.plot(x_values, y_values)
plt.xlabel('Time')
plt.ylabel('Accumulated Price')
plt.title('Expense Accumulation Graph')
plt.show()
