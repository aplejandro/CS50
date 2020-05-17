from cs50 import *

def main():
    strcard = input("Number: ")
    cc_number=int(strcard)
    #print(cc_number)
    #print(len(strcard))
    l = list(strcard)
    digit1 = 0
    digit2 = 0
    sum_of_double_odds = 0
    sum_of_evens = 0
    num_digits = 0;

    while cc_number > 0:
        digit2=digit1
        digit1 = cc_number % 10

        if num_digits % 2 == 0:
            sum_of_evens += digit1
        else:
            multiple = 2 * digit1
            sum_of_double_odds += (multiple // 10) + (multiple % 10)

        cc_number //=10
        num_digits += 1

    checksum = (sum_of_evens + sum_of_double_odds) % 10 == 0
    #print(checksum)


    if len(strcard) >= 13 and len(strcard) <= 16 and l[0] =='4' and checksum:
        print("VISA")
    elif len(strcard) == 16 and l[0]=='5' and (l[1]=='1' or l[1]=='2' or l[1]=='3' or l[2]=='4' or l[1]=='5') and checksum:
        print("MASTERCARD")
    elif len(strcard) == 15 and l[0]=='3' and (l[1]=='4' or l[1]=='7') and checksum:
        print("AMEX")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()