#include <stdio.h>

int main() {
    int n;
    int i;
    // Use 'double' for sum and elements to handle potential decimal values
    // and ensure accurate division for the mean.
    double element, sum = 0.0, mean;

    // 1. Read the value of n from the first line of input.
    // The problem statement implies input will be piped, so prompts are removed.
    scanf("%d", &n);

    // 2. Loop 'n' times to read each space-separated number.
    for (i = 0; i < n; i++) {
        scanf("%lf", &element);
        sum += element; // Add the current element to the sum.
    }

    // 3. Calculate the mean.
    // It's good practice to check if n is not zero to avoid division by zero error.
    if (n > 0) {
        mean = sum / n;
    } else {
        mean = 0.0; // Define mean as 0 if there are no elements.
    }

    // 4. Print the results in the required format.
    // "%.0f" prints the sum without any decimal places, as in the sample.
    // "%.2lf" prints the mean with exactly two decimal places.
    printf("Sum: %.0f\n", sum);
    printf("Mean: %.2lf\n", mean);

    return 0;
}