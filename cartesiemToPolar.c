/*
Write a program to recieve cartesiem coordinates (x, y) of a 
point and convert them into polar coordinates (r, theta).
hint: r = sqrt(x*x + y*y) and theta = atan2(y, x)
*/


#include<stdio.h>
#include<math.h>

int main(){
    // let's check how many variable we required.
    // value will be in deciman so using double.
    double x,y; // for coordinates.
    double r;   // for radius.
    double PI = 3.141;
    double theta_rad;  //angle in radius
    double theta_deg;  // angle in degree

    //Taking input
    printf("--- Cartesiem to Polar converter---\n");
    printf("Enter the x coordinate: ");
    if(scanf("%lf", &x) != 1){
        printf("Invalid input for x. \n");
        return 1;
    }
    printf("Enter the y coordinate: ");
    if(scanf("%lf", &y) != 1){
        printf("Invalid input for y.  \n");
    }

    //Cartesiem logic
    //step 1: calculate the radius(r)
    //pythagoras theoram
    r = sqrt(x*x + y*y);

    //step 2: calculate the angle (theta) in radius
    // atan2(y, x) handles all four quadrants corrently
    theta_rad = atan2(y, x);

    //step 3: convert radians to degrees
    // fromula: degrees = radians * (180/PI)
    theta_deg = theta_rad * (180 / PI);

    //output
    printf("\n ----- Conversion Results -------\n");
    printf("Cartesiem (x, y): (%.4f, %.4f)\n", x, y);
    printf("---------------------------\n");

    printf("Polar radius (r): %.4f\n", r);
    printf("Polar angle (theta): \n");
    printf("---> Radians: %.4f\n", theta_rad);
    printf("---> Degrees: %.4f\n", theta_deg);

    printf("\n Polar coordinates (r, theta) in Degrees: (%.4f, %.2f degrees)\n", r, theta_deg);

    return 0;
}