#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h = get_int("Height ");
    while (h<1 || h >8) {
    h = get_int("Height ");
    if(h>= 1 && h <=8){
        break;
    }
    }
    for(int i = 1; i <= h ; i++){
        for (int left_spaces = h - i; left_spaces > 0; left_spaces--)
        {
            printf(" ");
        }

        for (int lhashes = 1; lhashes <= i; lhashes++)
        {
            printf("#");
        }

        printf("  ");

        for (int rhashes = 1; rhashes <= i; rhashes++)
        {
            printf("#");
        }


        printf("\n");

    }
}