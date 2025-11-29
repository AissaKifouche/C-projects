#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,i,fact,somme=0;
    printf("A strong number is a special number whose sum of the factorials of its digits is equal to the original number \n\n\n");
    printf("enter a positive integer \n");
    scanf("%d", &n);
    b=n;
    while(n>0){
        a=n%10;
        fact=1;
    for(i=1;i<=a;i++){
        fact=fact*i;
    }
    somme=somme+fact;
    n=n/10;
    }
    if (b == somme) printf("The number you entered is a strong number \n");
    else printf("the number you entered is not a strong number\n");
    return 0;
}
