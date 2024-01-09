import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {} # creates an empty dictionary

    for row in reader: # iterates over each row in the csv files
        state = row['state']
        cases = int(row['cases'])

        if state not in new_cases:
            new_cases[state] = []

        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)

        new_cases[state].append(cases - new_cases[state][-1] if new_cases[state] else cases)

    return new_cases








# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        cases = new_cases[state]
        week = cases[-7:]
        sumofweek = sum(week)
        try:
            average = sumofweek / 7
            print(f"{state} had a 7-day average of {average:.0f}.")
        except ZeroDivisionError:
            print(f"{state} does not have enough data for a 7-day average.")



main()
