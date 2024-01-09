# TODO

text = input("Text: ")

letters = 0
words = 0
fullsentences = 0

for char in text:
    if char.isalpha():
        letters += 1

for char in text:
    if char.isspace():
        words += 1

words += 1

for char in text:
    if char in ['!', '?', '.']:
        fullsentences += 1

L = (letters / words) * 100
S = (fullsentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade {index}")