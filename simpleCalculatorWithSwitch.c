#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    float f;
    char c;
    printf("Enter two integers \n");
    scanf("%d%d",&a,&b);
    printf("To perform an addition, choose the operator + \n");
    printf("To perform a subtraction, choose the operator - \n");
    printf("To perform a division, choose the operator / \n");
    printf("To perform a multiplication, choose the operator * \n");
    scanf(" %c",&c);
    switch (c) {
    case '+' : printf("%d + %d = %d",a,b,a+b);
    break;
    case '-' : printf("%d - %d = %d",a,b,a-b);
    break;
    case '*' : printf("%d x %d = %d",a,b,a*b);
    break;
    case '/' : if (b!=0) {
    f=(float)a/b;
    printf("%d / %d = %f",a,b,f);
    }
    else printf(" can't devide by 0 \n");
    break;
    }
    return 0;
}
