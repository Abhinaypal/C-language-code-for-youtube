#include<stdio.h>
int main(){
    int num; // variable to store the user's input
    int sum = 0; // initialize the sum to 0
    int digit;  // variable to temporarily hold the last digit

    // ask the user for the number
    printf("Enter a number (e.g., 12345): ");
    scanf("%d", &num);

    //store the original in a temporary variable for the final print statement
    int originalNumber = num;

    // start a loop that runs as long as the number is greater than 0
    while (num > 0) {
        //get the last digit using the modulus operator
        digit = num % 10;

        // add the extracted digit to the sum
        sum = sum + digit;

        // remove the last digit using integer division
        num = num / 10;
    }

    //when the loop finishes, print the final sum
    printf("the sum of the digits in %d is: %d\n", originalNumber, sum);

    return 0;
}