#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
    void palindrom(char word[])
    {
        int i=strlen(word);
        char drow[i+1];
        for(int x=0;x<=i;x++)
           {
              drow[x]=word[i-x-1];
           }
        drow[i]='\0';
        if(strcmp(drow,word)==0)
        printf("%s is a palindrom word\n",word);
        else printf("%s is not a palindrom word",word);
    }

int main()
{
    char s[100];
    printf("enter a word\n");
    scanf("%s",&s);
    palindrom(s);
    return 0;
}
