#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int min=0,max=100;
    srand(time(NULL));
    int mist=(rand()%(max-min+1))+min;
    int a;
    do
    {
        printf("Guess the mystrious number: ");
        scanf("%d",&a);
        if(a==mist)
        {
            printf("\nGreat right answer");
        }
        else if (a>mist)
        {
            printf("\nWrong, the mystrious number is smaller \n");
        }
        else
        {
            printf("\nWrong, the mystrious number is bigger \n");
        }
    }while(a!=mist);
    printf("Hello world!\n");
    return 0;
}
