#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkPowersOfThree(int n) {
    while (n > 0) {
        if (n % 3 == 2) return false;
        n /= 3;
    }
    return true;
}
int main()
{
    int n;
  scanf("%d",&n);
  printf("%d",checkPowersOfThree(n));
    return 0;
}
