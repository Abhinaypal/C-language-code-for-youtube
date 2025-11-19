//write a c program to find whether the year is leap year or not.
//using nested if else statement.
// year%400 == 0 and should also dibisible by 4 
//year % 100 == 0
#include<stdio.h>
int main(){
    int year;

    printf("Enter the year: ");
    scanf("%d", &year);



    // //using nested if else
    if(year % 4 == 0){              //if year divisible by 4 and not by 100 then it will be leap year
        if(year % 100 == 0){        //if year divisible by 100 then will not be leap year
            if(year % 400 == 0){    //if the year divisible by 4 and 400 then it will be leap year
                printf("%d is the leap year. \n", year);
            }
            else{
                printf("%d is not a leap year. \n", year);
            }
        }
        else {
            printf("%d is the leap year. \n", year);
        }
    }
    else printf("%d is not a leap year. \n", year);


    // using if else ladder
    //if the year divisible by 400 then it will be leap year
    // if(year % 400 == 0){
    //     printf("%d is the leap year. \n", year);
    // }
    // //if the year divisible by 100 and not by 400 then it will not be leap year
    // else if(year % 100 == 0){
    //     printf("%d is not a leap year. \n", year);
    // }
    // //if the year divisible by 4 and not by 100 then it will be a leap year
    // else if(year % 4 == 0){
    //     printf("%d is the leap year. \n", year);
    // }
    // else{
    //     printf("%d is not a leap year. \n", year);
    // }
    return 0;
}