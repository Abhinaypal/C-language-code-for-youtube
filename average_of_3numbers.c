#include<stdio.h>

int main(){
    int a, b, c;
    float average;

    // read three integers frim the user
    printf("enter three numbers :");
    scanf("%d %d %d", &a, &b, &c);

    //calculate average
    average = (a+b+c)/3.0;

    //print the average as a floating point numbers
    printf("the average is: %.2f\n", average);

    return 0;
}