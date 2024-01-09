from cs50 import SQL

db = SQL("sqlite:///favourites.db")

favourite = input("Favourite: ")

rows =db.execute("SELECT COUNT* FROM favourites WHERE problem ='7'")

row = row[0]
print(row["n"])  



































#import csv

#with open("firstsqlfile.csv", "r") as file: #reading the file
 #   reader = csv.DictReader(file)  #setting a variable that reads the file #changing reader to dictreader that returns a dictionary with pair values instead of just a list
    #next(row) #withou thtis the whole column is read including the header, to avoid this you use this one to skip the header

    #scratch = 0
   # c = 0
   # python = 0     # or you can do
   #scratch, c, python = 0, 0, 0        #problem, hard coding this might be an issue as if new languages pop up new lines have to be added

 #   counts = {} #or dict()

   # for row in reader:
      #  favourite = row["language"] #prints variable under the 2nd column of a spreadsheet, changing row[1] to row language works if file is dictionary as the header becomes the key
      #  if favourite in counts:
     #       counts[favourite] += 1 #add 1 to a language
    #    else:
   #         count[favourite] =1 #add a new language



 #       if favourite == "Scratch":               old way to do it
   #         scratch += 1
    #    elif favourite == "C":
     #       c+=1
      #  elif favourite =="Python":
       #     python += 1
#def get_value(language):
  #  return counts[language]

#for favourite in sorted(counts, key=lamba language: counts[language] , reverse=True):  #will print out all languages in the counts  #sourted will organize counts automatically by alphabetically and can take other arguments
 #   print(f"{favourite}: {count[favourite]}")