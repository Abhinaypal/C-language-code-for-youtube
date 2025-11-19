/*
Wind chill factor is the felt air temperature on exposed skine due to wind. The wind chill temperature
is always lower than the air temperature , and is calculated as per the following formula:
wcf = 35.74 + 0.6215t + (0.4275t-35.75) * v^0.16
where t is temperature and v is wind velocity,
Write a c program to recieve values of t and v and calculate wind chill factor(wcf).
*/


#include<stdio.h>
#include<math.h>

//function to calcualte the wind chill factor
double calculate_wcf(double t, double v){
    //according to the National Weather Service, the wind chill is not defined when wind speed is less than 3 mph.
    if(v < 3.0){
        printf("\n[Note: wind chill factor formula is typically most accurate for wind speeds > 3 mph.]\n");
    }

    //step 1: calculate v^0.16
    double v_power = pow(v, 0.16);


    //step 2: calculate the second bracket term (0.4275t - 35.75)
    double bracket_term = (0.4275 * t) - 35.75;


    //step 3: combine all parts of the formula
    double wcf = 35.74 + (0.6215 * t) + (bracket_term * v_power);

    return wcf;
}

int main(){
    //declare variables as double for accurate floating point arithmetic calculation
    double temperature_t, velocity_v, wcf_result;

    printf("--- Wind chill factor calculator ---\n");
    printf("This formula is typically used with: temperature (t) in fahrenheit and wind velocity (v) in miles per hour (mph),\n\n");

    //get temperature input (t)
    printf("Enter the air temperature (t, usually in fahrenheit): ");

    //use an input loop to handle invalid input
    while(scanf("%lf", &temperature_t) != 1){
        //clear the input buffer if input was not a number.
        while(getchar() != '\n');
        printf("Invalid input: Please enter a numerical value for temperature: ");


    }

    //get wind velocity input(v)
    printf("Enter the wind velocity (v, usually in mph): ");

    //use an input loop to handle invalid input
    while(scanf("%lf", &velocity_v) != 1 || velocity_v < 0){
        while(getchar() != '\n');
        printf("Invalid input, Please enter a non-negative numerical value for velocity: ");
    }

    //calculate the wcf
    wcf_result = calculate_wcf(temperature_t, velocity_v);

    //display the result
    printf("\n ---------------------------------------------\n");
    printf("Air temperature (t): %.2lf defrees\n", temperature_t);
    printf("Wind velocity (v): %.2lf mph\n", velocity_v);

    printf("-----------------------------------------------\n");
    printf("Calculated wind chill factor: %.2lf degrees\n", wcf_result);

    //quick check based on the definition: wcf should be <= T
    if(wcf_result > temperature_t){
        printf("\n[Warning: The calculated wcf (%.2lf) is higher than the air temp (%.2lf). This indicates the input values may be outside the formula's valid range.]\n", wcf_result, temperature_t);

    }
    printf("================================================\n");
}