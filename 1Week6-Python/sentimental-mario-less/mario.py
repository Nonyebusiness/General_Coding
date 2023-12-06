# TODO

def getinput():
    while True:
        try:
            height = int(input("Height: "))
            if height > 0 and height < 9:
                return height
            else:
                print("not a number between 1-8")
        except ValueError:
            print("not a number")

def main():
    pyramidheight = getinput()

    for y in range(pyramidheight):

        for x in range(pyramidheight - y  - 1):
            print(" ", end='')
        for z in range(y + 1):
            print("#", end='')
        print()


main()
