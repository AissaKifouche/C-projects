#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pascal[7][7];
    for(int j=0;j<=6;j++)
    {
        for(int i=0;i<=j;i++)
        {
            if(i==0 || i==j) pascal[i][j]=1;
            else pascal[i][j]=pascal[i-1][j-1] + pascal[i][j-1];
            printf("%d ",pascal[i][j]);
        }
        printf("\n");
    }
    return 0;
}
