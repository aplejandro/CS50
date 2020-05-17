from cs50 import *
import math

def main():
    letras=0
    palabras=1
    oraciones=0
    G=0

    texto = get_string("Text: ")
    n = len(texto)
    for i in range(n):
        if texto[i].isalnum()==True:
            letras+=1
    for i in range(n):
        if texto[i].isspace()==True:
            palabras+=1
    for i in range(n):
        if texto[i]=="?" or texto[i]=="." or texto[i]=="!":
            oraciones+=1



    L = 100 * letras / palabras
    S = 100 * oraciones / palabras

    G = round((0.0588 * L) - (0.296 * S) - 15.8)

    if (G < 16 and G >= 1):
        print("Grade ", str(G))
    elif (G >= 16):
        print("Grade 16+")
    else:
        print("Before Grade 1")


if __name__ == "__main__":
    main()