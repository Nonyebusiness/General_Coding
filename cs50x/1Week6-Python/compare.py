from cs50 import get_int

s = input("s: ")

t=s.capitalize()

print(f"s: {s}")
print(f"t: {t}")


def notusing1():
    s = input("s: ")
    t= input("t: ")

    if s == t:
        print("Same")
    else:
        print("Different")




















def notusing():
    x = get_int("x: ")
    y = get_int("y: ")

    if x < y:
        print("x is less than y")
    elif x > y:
        print("x is greater than y")
    else:
        print("x is equal to y")