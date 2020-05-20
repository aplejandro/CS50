import cs50
import csv
from sys import *
import string

if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit()
elif len(argv) == 2 and (argv[1].endswith(".csv")):
    name_split=[]
    db = cs50.SQL("sqlite:///students.db")
    with open(argv[1], "r") as cfile:
        characters = csv.DictReader(cfile)
        for row in characters:
            name_split = row["name"].split()
            if len(name_split) == 2:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)",
                name_split[0],None,name_split[1],row["house"],row["birth"])
            elif len(name_split) == 3:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?,?,?,?,?)",
                name_split[0],name_split[1],name_split[2],row["house"],row["birth"])
                
                
            
            



