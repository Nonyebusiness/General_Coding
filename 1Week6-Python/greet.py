from sys import argv

for arg in argv[1:1]: #the square bracket lets you start and stop at certain points of an array first number being start and last one being end
    print(arg)


def notusing2():
    for i in range(len(argv)):
        print(argv[i])


def notusingthisanymore():
    if len(argv) == 2:
        print(f"hello, {argv[1]}")
    else:
        print("hello, world")