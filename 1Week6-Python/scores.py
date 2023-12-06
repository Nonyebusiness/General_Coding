from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score) #or you can do scores += [score]

average = sum(scores) / len(scores) #sum is all the socres added and len is the length of the score
print(f"Average: {average}")



def main():
    scores =[72, 73, 33]

    average = sum(scores) / len(scores) #sum is all the socres added and len is the length of the score
    print(f"Average: {average}")