#include <stdio.h>
#include <stdlib.h>

int main()
{
    float average;
    printf(" enter the average \n");
    scanf("%f", &average);
    if (average<0 || average>20 ) printf("wrong average \n");
    if (0<average && average<10) printf("deferred \n");
    else if (10<=average && average<15) printf("admitted \n");
    else if(average>=15 && average<=20) printf("admitted: Excellent \n");
     return 0;
}

