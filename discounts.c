#include <stdio.h>
#include <stdlib.h>

int main()
{
    int it;
    float up,abt,toam,dis,tva;
    printf("please enter the number of items\n");
    scanf("%d",&it);
    printf("please enter the unit price \n");
    scanf("%f",&up);
    abt=it*up;
    printf("the amount price is %f DZD \n",up);
    printf("the amount before tax is %f DZD\n",abt);
    if (abt>=100) {
         dis=0.2*abt;
         printf("you've won a discount of 20%% !congratulations \n");
    }
    else if (abt>=50) {
        dis=0.1*abt;
        printf("you've won a discount of 10%% !congratulations \n");
    }
    else printf("you don't have a discount \n");
    tva=0.17*abt;
    printf("the tax value is %f DZD \n",tva);
    toam=abt+(0.17*abt)-dis;
    printf("the total amount with tva and discount is %f DZD \n",toam);
    return 0;
}
