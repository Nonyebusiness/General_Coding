for i in range(3):
    for j in range(3):
        print("#", end="")
    print()



#call main with main() to get the coded working here at the bottom
def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        try:  #wwill try get an interger if it doesnt work the code continues but since its a loop the try will be called again
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an interger")

