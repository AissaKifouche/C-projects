#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sword[6]="aissa";//The secret word to search for
    
    char rep[6]="*****";
    printf("Pendu is a game to guess the secret word\n");
    int chance=10;
    char c;
    int found;
    do
    {
        printf("\nEnter a character: ");
        scanf("%c",&c);
        fflush(stdin);

        found=0;
        for (int i = 0; i < strlen(sword); i++)
        {
            if (tolower(sword[i])==tolower(c))
            {
                rep[i]=sword[i];
                found=1;
            }
        }
        if (strcmp(rep,sword)==0)
        {
            printf("\nWell played you guessed the secret word\n");
        }
        else
        {
            if (found)
            {
                printf("\n%s",rep);
                printf("\nYou still have %d chances",chance);
            }
            else
            {
                chance--;
                printf("\nWrong answer, you have %d chances left",chance);
            }
        }
    } while ( strcmp(sword,rep)!=0 && chance>0);

    if (strcmp(sword,rep)!=0)
    {
        printf("\nLoser, you failed to guess the secret word and it was %s",sword);
    }


    return 0;
}

