#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   float A,P,D;
   const float pi;
   printf("enter pi \n");
   scanf("%f",&pi);
   printf("enter the diameter: \n");
   scanf("%f",&D);
   A=D*D*pi;
   P=D*pi;
   printf("Area=%lf \n",A);
   printf("Perimeter=%.5f\n",P);
   scanf("%f",&pi);
   A=pi+pi;
   printf("a=%f",pi);
    return 1;
}
