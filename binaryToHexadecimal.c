#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("enter your number \n");
    int i=0,a,n;
    scanf("%d",&n);
    char c;
    char hexa[50];
    do
    {
        a=n%16;

    if (a<10)
    {
      c=a+'0';
    }
    else {c='A'+(a-10);}
    hexa[i]=c;
    n/=16;
    i++;


    } while (n!=0);


    hexa[i]='\0';

    printf("%s",strrev(hexa));
    return 0;
}
