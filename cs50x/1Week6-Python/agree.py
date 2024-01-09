s = input("Do you agree? ")

s = s.lower()

if s in ["y", "yes"]:
    print("Agreed.")
elif s == "n" or s == "N":
    print("Not agreed.")
