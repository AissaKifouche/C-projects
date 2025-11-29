#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,d,e,g;
    float f;
    char c;
    printf("Enter two integers \n");
    scanf("%d%d",&a,&b);
    printf("To perform an addition, choose the operator + \n");
    printf("To perform a subtraction, choose the operator - \n");
    printf("To perform a division, choose the operator / \n");
    printf("To perform a multiplication, choose the operator x \n");
    fflush(stdin);
    scanf("%c",&c);
    if ( c == '+' ){
        d=a+b;
        printf("%d+%d=%d\n",a,b,d);
    }
    else if ( c == '-' ){
        e=a-b;
        printf("%d-%d=%d\n",a,b,e);
    }
    else if ( c == '/' ){
            if (b!=0){
        f=a/b;
        printf("%d/%d=%f\n",a,b,f);
    }
    else printf(" can't devide by 0 \n"); }
    else if ( c == 'x' ){
        g=a*b;
        printf("%d x %d=%d\n",a,b,g);
    }
    return 0;
}
