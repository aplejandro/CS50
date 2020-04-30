#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

bool validate(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    string keys = argv[1];
    if (validate(keys) == false)
    {
        return 1;
    }
    int keys_int[26];
    for (int j=0 ; j < strlen(keys) ; j++)
    {
        if(isupper(keys[j]))
        {
            keys_int[j] = (keys[j]) - ('A' + j);
            if (keys_int[j] < 0)
            {
                keys_int[j] += 26;
            }
        }
        if(islower(keys[j]))
        {
            keys_int[j] = (keys[j]) - ('a' + j);
            if (keys_int[j] < 0)
            {
                keys_int[j] += 26;
            }
        }
    }
 
    string text = get_string("plaintext: ");
    string cipher = text;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            switch (text[i])
            {
                case 'a':
                cipher[i] = (((text[i]-'a') + keys_int[0]) % 26) + 'a';
                break;
                case 'b':
                cipher[i] = (((text[i]-'a') + keys_int[1]) % 26) + 'a';
                break;
                case 'c':
                cipher[i] = (((text[i]-'a') + keys_int[2]) % 26) + 'a';
                break;
                case 'd':
                cipher[i] = (((text[i]-'a') + keys_int[3]) % 26) + 'a';
                break;
                case 'e':
                cipher[i] = (((text[i]-'a') + keys_int[4]) % 26) + 'a';
                break;
                case 'f':
                cipher[i] = (((text[i]-'a') + keys_int[5]) % 26) + 'a';
                break;
                case 'g':
                cipher[i] = (((text[i]-'a') + keys_int[6]) % 26) + 'a';
                break;
                case 'h':
                cipher[i] = (((text[i]-'a') + keys_int[7]) % 26) + 'a';
                break;
                case 'i':
                cipher[i] = (((text[i]-'a') + keys_int[8]) % 26) + 'a';
                break;
                case 'j':
                cipher[i] = (((text[i]-'a') + keys_int[9]) % 26) + 'a';
                break;
                case 'k':
                cipher[i] = (((text[i]-'a') + keys_int[10]) % 26) + 'a';
                break;
                case 'l':
                cipher[i] = (((text[i]-'a') + keys_int[11]) % 26) + 'a';
                break;
                case 'm':
                cipher[i] = (((text[i]-'a') + keys_int[12]) % 26) + 'a';
                break;
                case 'n':
                cipher[i] = (((text[i]-'a') + keys_int[13]) % 26) + 'a';
                break;
                case 'o':
                cipher[i] = (((text[i]-'a') + keys_int[14]) % 26) + 'a';
                break;
                case 'p':
                cipher[i] = (((text[i]-'a') + keys_int[15]) % 26) + 'a';
                break;
                case 'q':
                cipher[i] = (((text[i]-'a') + keys_int[16]) % 26) + 'a';
                break;
                case 'r':
                cipher[i] = (((text[i]-'a') + keys_int[17]) % 26) + 'a';
                break;
                case 's':
                cipher[i] = (((text[i]-'a') + keys_int[18]) % 26) + 'a';
                break;
                case 't':
                cipher[i] = (((text[i]-'a') + keys_int[19]) % 26) + 'a';
                break;
                case 'u':
                cipher[i] = (((text[i]-'a') + keys_int[20]) % 26) + 'a';
                break;
                case 'v':
                cipher[i] = (((text[i]-'a') + keys_int[21]) % 26) + 'a';
                break;
                case 'w':
                cipher[i] = (((text[i]-'a') + keys_int[22]) % 26) + 'a';
                break;
                case 'x':
                cipher[i] = (((text[i]-'a') + keys_int[23]) % 26) + 'a';
                break;
                case 'y':
                cipher[i] = (((text[i]-'a') + keys_int[24]) % 26) + 'a';
                break;
                case 'z':
                cipher[i] = (((text[i]-'a') + keys_int[25]) % 26) + 'a';
                break;
                case 'A':
                cipher[i] = (((text[i]-'A') + keys_int[0]) % 26) + 'A';
                break;
                case 'B':
                cipher[i] = (((text[i]-'A') + keys_int[1]) % 26) + 'A';
                break;
                case 'C':
                cipher[i] = (((text[i]-'A') + keys_int[2]) % 26) + 'A';
                break;
                case 'D':
                cipher[i] = (((text[i]-'A') + keys_int[3]) % 26) + 'A';
                break;
                case 'E':
                cipher[i] = (((text[i]-'A') + keys_int[4]) % 26) + 'A';
                break;
                case 'F':
                cipher[i] = (((text[i]-'A') + keys_int[5]) % 26) + 'A';
                break;
                case 'G':
                cipher[i] = (((text[i]-'A') + keys_int[6]) % 26) + 'A';
                break;
                case 'H':
                cipher[i] = (((text[i]-'A') + keys_int[7]) % 26) + 'A';
                break;
                case 'I':
                cipher[i] = (((text[i]-'A') + keys_int[8]) % 26) + 'A';
                break;
                case 'J':
                cipher[i] = (((text[i]-'A') + keys_int[9]) % 26) + 'A';
                break;
                case 'K':
                cipher[i] = (((text[i]-'A') + keys_int[10]) % 26) + 'A';
                break;
                case 'L':
                cipher[i] = (((text[i]-'A') + keys_int[11]) % 26) + 'A';
                break;
                case 'M':
                cipher[i] = (((text[i]-'A') + keys_int[12]) % 26) + 'A';
                break;
                case 'N':
                cipher[i] = (((text[i]-'A') + keys_int[13]) % 26) + 'A';
                break;
                case 'O':
                cipher[i] = (((text[i]-'A') + keys_int[14]) % 26) + 'A';
                break;
                case 'P':
                cipher[i] = (((text[i]-'A') + keys_int[15]) % 26) + 'A';
                break;
                case 'Q':
                cipher[i] = (((text[i]-'A') + keys_int[16]) % 26) + 'A';
                break;
                case 'R':
                cipher[i] = (((text[i]-'A') + keys_int[17]) % 26) + 'A';
                break;
                case 'S':
                cipher[i] = (((text[i]-'A') + keys_int[18]) % 26) + 'A';
                break;
                case 'T':
                cipher[i] = (((text[i]-'A') + keys_int[19]) % 26) + 'A';
                break;
                case 'U':
                cipher[i] = (((text[i]-'A') + keys_int[20]) % 26) + 'A';
                break;
                case 'V':
                cipher[i] = (((text[i]-'A') + keys_int[21]) % 26) + 'A';
                break;
                case 'W':
                cipher[i] = (((text[i]-'A') + keys_int[22]) % 26) + 'A';
                break;
                case 'X':
                cipher[i] = (((text[i]-'A') + keys_int[23]) % 26) + 'A';
                break;
                case 'Y':
                cipher[i] = (((text[i]-'A') + keys_int[24]) % 26) + 'A';
                break;
                case 'Z':
                cipher[i] = (((text[i]-'A') + keys_int[25]) % 26) + 'A';
                break;

            }
        }
        else
        {
            cipher[i] = text[i];
        }
    }


    printf("ciphertext: ");
    for (int i = 0; i < strlen(cipher); i++){
        printf("%c",cipher[i]);
    }
    printf("\n");
}

bool validate(string key)
{
    int matches = 0;
    if (strlen(key) == 26)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if(tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }
        if(matches == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}