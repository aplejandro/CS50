#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#define L 45
#define N 20
#define K 10


char tabla[N][K][L + 1];



int main()
{
    strcpy(tabla[0][0],"=");
    strcpy(tabla[2][5],"=");
    strcpy(tabla[8][4],"=");
    strcpy(tabla[19][9],"=");
     strcpy(tabla[0][1],"X");
    strcpy(tabla[2][6],"X");
    strcpy(tabla[8][7],"X");
    strcpy(tabla[19][0],"X");
    printf("Iniciando\n");
    for (int i=0;i < N;i++)
{
    for (int n=0;n < K;n++)
    {
        if(strcmp(tabla[i][n],"")==0)
    strcpy(tabla[i][n],"O");
}
}
 printf("Tabla llena\n");
    for (int i=0;i < N;i++)
{
    for (int n=0;n < K;n++)
    {
    printf("%s ",tabla[i][n]);
}
printf("\n");
}

}
