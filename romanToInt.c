//Roman number to integers

//for example 2 is written as II in roman numeral, just two ones added together. 
//12 is written as XII, which is simply X+II.
//27 written as XXVIIV, which is XX + V + II.
//IV = V-I
/*
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
*/


#include<stdio.h>
#include<string.h>

//value of character
int getValue(char c){
    switch (c)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

//logic function
int romanToInt(char* s){    //{5, 6, 2, 4}
    int res = 0;
    int i = 0;

    while(s[i] != '\0'){
        int value1 = getValue(s[i]);        //VVIMCM
        int value2 = getValue(s[i+1]); //value of next char

        if(value1 < value2){
            res = res - value1;
        }
        else{
            res = res + value1;
        }
        i++;
    }
    return res;
}

int main(){
    //create a char array to store the value
    char s[20];

    //taking the input from user
    printf("Enter a roman number (e.g., I, II, VI, MCM): ");
    scanf("%s", s); //do not need to add the & for char

    //calling the function
    int output = romanToInt(s);

    printf("Interger value: %d\n", output);

    return 0;
}