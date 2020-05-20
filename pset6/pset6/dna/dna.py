import csv
from csv import reader, DictReader
from sys import argv

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit()
    datalist=[]
    seclist=[]
    with open(argv[1]) as datafile:
        data = csv.reader(datafile)
        for row in data:
            datalist.append(row)
    datalist.pop(0)
    with open(argv[2]) as secfile:
        sec = reader(secfile)
        for row in sec:
            seclist.append(row)
    dna=seclist[0][0]
    if argv[1] == "databases/large.csv":
        sd={'AGATC': 1,'TTTTTTCT':1,'AATG':1,'TCTAG':1,'GATA':1,'TATC':1,'GAAA':1,'TCTG':1}
        for key in sd:
            l = len(key)
            tempMax = 0
            temp = 0
            for i in range(len(dna)):
                while temp > 0:
                    temp -= 1
                    continue
                if dna[i: i + l] == key:
                    while dna[i - l: i] == dna[i: i + l]:
                        temp += 1
                        i += l
                if temp > tempMax:
                    tempMax = temp
            sd[key] += tempMax
        for row in datalist:
            if sd["AGATC"] == int(row[1]) and sd["TTTTTTCT"] == int(row[2]) and sd["AATG"] == int(row[3]) and sd["TCTAG"] == int(row[4]) and sd["GATA"] == int(row[5]) and sd["TATC"] == int(row[6]) and sd["GAAA"] == int(row[7]) and sd["TCTG"] == int(row[8]):
                print(row[0])
                break
        else:
            print("No match")
    elif argv[1] == "databases/small.csv":
        sd={'AGATC': 1,'AATG':1,'TATC':1}
        for key in sd:
            l = len(key)
            tempMax = 0
            temp = 0
            for i in range(len(dna)):
                while temp > 0:
                    temp -= 1
                    continue
                if dna[i: i + l] == key:
                    while dna[i - l: i] == dna[i: i + l]:
                        temp += 1
                        i += l
                if temp > tempMax:
                    tempMax = temp
            sd[key] += tempMax
        for row in datalist:
            if sd["AGATC"] == int(row[1]) and sd["AATG"] == int(row[2]) and sd["TATC"] == int(row[3]):
                print(row[0])
                break
        else:
            print("No match")


if __name__ == "__main__":
    main()