from cs50 import *
import csv
from sys import *
import string

if len(argv) != 2:
    print("Usage: python roster.py house")
    exit()
elif len(argv) == 2 and (argv[1]=="Gryffindor" or argv[1]=="Hufflepuff" or argv[1]=="Ravenclaw" or argv[1]=="Slytherin"):
    db = SQL("sqlite:///students.db")
    student = db.execute("SELECT first,middle,last, birth FROM students WHERE house = (?) ORDER BY last , first", argv[1])
    for row in student:
        if row["middle"] == None:
            print(row["first"]+" "+row["last"]+", born "+str(row["birth"]))
        elif row["middle"] != None:
            print(row["first"]+" "+row["middle"]+" "+row["last"]+", born "+str(row["birth"]))