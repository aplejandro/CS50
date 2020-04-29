#include <stdio.h>
#include <cs50.h>
int nod(long long k);
int first(long long k);
int first2(long long x);
int main(void)
{
    int sump = 0, sumi = 0, d1 = 0;
    long long n=get_long_long("Number: ");
    long long nc=n;
    int l=nod(n);
    for(int i=0;i<l;i++){
        d1 = n % 10;
        if (i % 2 == 0)
            sump += d1;
        else{
            int multiply = 2 * d1;
            sumi += (multiply / 10) + (multiply % 10);
            }
        n /= 10;
     }
    bool checksum = (sump + sumi) % 10 == 0;
    //printf("%d",first2(nc3));

    if (nod(nc) >= 13 && nod(nc) <= 16 && checksum && first(nc)==4){
        printf("VISA\n");
    }
    else if (nod(nc) == 16 && checksum && first2(nc)>=51 && first2(nc)<=55){
        printf("MASTERCARD\n");
    }
    else if (nod(nc) == 15 && checksum && (first2(nc)==34 || first2(nc)==37)){
        printf("AMEX\n");
    }
    else{
        printf("INVALID\n");
    }

}

int nod(long long k){
    int number_of_digits = 0;
    do{
     ++number_of_digits;
     k /= 10;
     }while (k);
    return number_of_digits;
}
int first(long long k){
    while (k >= 10)
    {
        k /= 10;
    }
    return k;
}
int first2(long long x){
    while (x >= 100)
    {
        x /= 10;
    }
    return x;
}