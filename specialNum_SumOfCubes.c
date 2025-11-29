#include <stdio.h>
#include <math.h>

// Function to calculate the sum of cubes of the digits of a number
int sum_of_cubes(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10; // Extract the last digit
        sum += pow(digit, 3); // Add the cube of the digit
        num /= 10;           // Remove the last digit
    }
    return sum;
}

// Function to find and display numbers satisfying the condition
void find_special_numbers(int N) {
    printf("Special numbers less than %d:\n", N);
    for (int i = 0; i < N; i++) {
        if (i == sum_of_cubes(i)) {
            printf("%d ", i); // Print the number if it matches the condition
        }
    }
    printf("\n");
}

// Main function
int main() {
    int N;
    printf("Enter a natural number N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Please enter a positive natural number.\n");
        return 1;
    }

    find_special_numbers(N);
    return 0;
}
