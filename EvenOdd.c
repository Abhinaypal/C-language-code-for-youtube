#include <stdio.h>

int main() {
    int n;
    int i;
    int num;
    int even_count = 0;
    int odd_count = 0;

    // 1. Read the value of 'n' from the first line of input.
    // Since the input format is fixed, prompts for the user are omitted.
    scanf("%d", &n);

    // 2. Loop 'n' times to read each space-separated integer.
    for (i = 0; i < n; i++) {
        scanf("%d", &num);

        // 3. Check if the number is even or odd using the modulo operator.
        // A number is even if it is perfectly divisible by 2.
        if (num % 2 == 0) {
            even_count++; // Increment the even counter.
        } else {
            odd_count++;  // Increment the odd counter.
        }
    }

    // 4. Print the final counts in the required format.
    printf("Even: %d\n", even_count);
    printf("Odd: %d\n", odd_count);

    return 0;
}