#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,x;
    printf("enter an integer \n");
    scanf("%d",&x);

    for (i=1 ; i<=x ; i=++){
        if ((x%i)==0) printf(" %d is a devider of %d \n",i,x);
    }
    return 0;
}
