import csv


with open("phonebook.csv", "a") #with will run all the coded then automatically close the file

    name = input("Name: ")
    number = input("Number: ")

    writer = csv.DictWriter(file, fieldnames=["names", "number"])
    writer.writerow({"name": name, "number": number}




def notusing1():
    people = {
        "Carter": "+1-617-495-1000",
        "David": "+1-949-468-2750"

    }

    name = input("Name: ")
    if name in people:
        number = people[name]
        print(f"Number: {number}")