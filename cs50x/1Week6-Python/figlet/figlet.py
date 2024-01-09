import pyfiglet
import sys


def main():
    if len(sys.argv) == 1:
        pigletuntransformed()
    elif sys.argv[1] == '-f' and sys.argv[2] in ['alphabet', 'rectangles', 'slant']:
        piglettransformed(sys.argv[2])
    else:
        print("Invalid usage")
        sys.exit(1)

def pigletuntransformed():
    user_input = input("Input: ")

    output = pyfiglet.figlet_format(user_input)

    print(f"Output: {output}")

def piglettransformed(font):
    user_input = input("Input: ")

    output = pyfiglet.figlet_format(user_input, font=font)

    print("Output: ")
    print(f"{output}")



main()