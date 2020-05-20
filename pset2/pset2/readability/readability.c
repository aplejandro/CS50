#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letras = 0, palabras = 1, oraciones = 0;
    string text = get_string("Text: ");


    for (int i = 0; i < strlen(text); i++)
    {
        //Contador de letras
        if (isalpha(text[i]))
        {
            letras += 1;
        }
        //Contador de palabras
        if (isspace(text[i]))
        {
            palabras += 1;
        }
        //Contador de oraciones
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            oraciones += 1;
        }
    }

    //calculando promedios
    //Promedio letras
    float L = 100 * (float) letras / (float) palabras;
    float S = 100 * (float) oraciones / (float) palabras;

    //Determiando el grad0
    float G = (0.0588 * L) - (0.296 * S) - 15.8;

    if (G < 16 && G >= 1)
    {
        printf("%f",G);
        printf("Grade %i\n", (int) round(G));
    }
    else if (G >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}