#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string k=argv[1];
    for (int j=0 ; j < strlen(k) ; j++)
    {
        if (!isdigit(k[j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key;
    key = atoi(k);
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string text = get_string("plaintext:: ");
    string cipher = text;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                cipher[i] = (((text[i]-'a') + key) % 26) + 'a';

            }
            else if (isupper(text[i]))
            {
                cipher[i] = (((text[i]-'A') + key) % 26) + 'A';
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