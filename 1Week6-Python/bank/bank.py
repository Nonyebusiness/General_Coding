import sys

def helloorsomethingelse():
    if greetingcompare[0:5] == 'hello':
        print("$0")
    else:
        print("$20")

greeting = input("Greeting: ")

greetingcompare = greeting.strip().lower()

if greetingcompare[0] != 'h':
    print("$100")
else:
    helloorsomethingelse()


