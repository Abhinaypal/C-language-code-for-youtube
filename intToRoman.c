// INTEGER TO ROMAN NUMBERS
//54321 //VI
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* intToRoman(int num){
    //storing the symbols and their values from upper to lower
    //there are total 13 combinations 
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    //*symbols[2] 5000  // VVVVIIXXXXCCCDD
    //allocating the memory to store the result
    //roman numbers are usually maximum 15-20 characters
    char* result = (char*)malloc(20 * sizeof(char));

    //now initialize a empty string so garbage value does'nt exist
    result[0] = '\0';

    //using loop for array
    for(int i = 0; i < 13; i++){
        //one more loop for checking if the number is greater than or not from current value
        while (num >= values[i]){
            //now apppending the string by symbol
            strcat(result, symbols[i]);
            //hello, bye == hellobye
            //now substracting value from number
            num = num - values[i];
        }
    }
    return result;
}

int main(){
    int number;

    //taking input from user
    printf("Enter an integer: ");
    scanf("%d", &number);

    //calling function
    char* romanNums = intToRoman(number);

    //now print the output
    printf("Roman numeral: %s\n", romanNums);

    //free memory
    free(romanNums);
    return 0;
}