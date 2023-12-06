a = 1
b = 1
counter = 2

while b <= 200:

    c = a + b

    a = b
    b = c
    counter += 1


print(f"number of loops: {counter}")