#include<stdio.h>
#include<math.h>

// define the earth radius provided in formula
#define R_MILES 3963.0
// define the conversion factor from statute miles to nautical miles
#define MILES_TO_NM_FACTOR 0.868976
#define M_PI 3.14159265358979323846
//now we are creating a function
double deg_to_rad(double deg){
    //M_PI is already defined in math.h
    return deg*(M_PI/180.0);
}

void read_double(const char *prompt, double *val){
    int read_status;

    do{
        printf("%s", prompt);
        //attempt to read a double

        read_status = scanf("%lf", val);

        //check if reading failed or if input stream closed
        if(read_status != 1){
            printf("Error: invalid input detected, Please enter a numerical value");

            while(getchar() != '\n' && !feof(stdin));
        }
    }
    while(read_status != 1);
}
//main function
int main(){
    //variable for latitude and longitude in degrees
    double L1_deg, L2_deg, G1_deg, G2_deg;

    //variable for latitude and longitude in radians
    double L1_rad, L2_rad, G1_rad, G2_rad;
    double dG_rad;   // difference in longitude (G2-G1) in radians

    double angle_cos;  // the value inside acos()
    double central_angle_rad;    // the angle between two points at centre
    double distance_miles;  //distance in statute miles
    double distance_nm;     //final dinstance in nautical miles


    printf("--- Great circle distance calculator ---\n\n");
    
    //step 1:  input coordinates in degrees.
    printf("---Location 1 ----\n");
    // printf("Enter latitude (L1 in degrees): ");
    // if(scanf("%lf", L1_deg) != 1){
    //     return 1;
    // }
    // printf("Enter the longitude (G1 in degrees): ");
    // if(scanf("%lf", G1_deg) != 1){
    //     return 1;
    // }


    // printf("--- Location 2 ---");
    // printf("Enter the latitude (L2 in degrees): ");
    // if(scanf("%lf", L2_deg) != 1){
    //     return 1;
    // }
    // printf("Enter the longitude (G2 in degrees): ");
    // if(scanf("%lf", G2_deg) != 1){
    //     return 1;
    // }

    read_double("enter latitude (L1 in degrees): ", &L1_deg);
    read_double("enter latitude (G1 in degrees): ", &G1_deg);

    printf("\n--- Location 2 ----\n");
    read_double("enter latitude (L2 in degrees): ", &L2_deg);
    read_double("enter latitude (G2 in degrees): ", &G2_deg);

    // step 2: convert degrees to radians
    L1_rad = deg_to_rad(L1_deg);
    L2_rad = deg_to_rad(L2_deg);
    G1_rad = deg_to_rad(G1_deg);
    G2_rad = deg_to_rad(G2_deg);

    // calculate the difference in longitude (dG)
    dG_rad = G2_rad - G1_rad;

    //calculate angle cosine and central angle---
    //calculate the term inside the cos^-1 function(angle_cos)
    // formula: (sin L1 * sin L2) + (cos L1 * cos L2 * cos(g2-G1))
    angle_cos = (sin(L1_rad) * sin(L2_rad)) + (cos(L1_rad) * cos(L2_rad) * cos(dG_rad));

    if(angle_cos > 1.0) angle_cos = 1.0;
    if(angle_cos < -1.0) angle_cos = -1.0;

    //calculate the centre angle
    central_angle_rad = acos(angle_cos);


    //calculate distance in statute miles ---
    distance_miles = R_MILES * central_angle_rad;

    // convert to nautical miles
    distance_nm = distance_miles * MILES_TO_NM_FACTOR;

    // output results
    printf("\n -- calculation summary --\n");
    printf("Distance in statute miles (using R = 3963): %2f mi\n", distance_miles);

    printf("-------------------------------\n");
    printf("Distance in nautical miles (D) : %2f NM \n", distance_nm);
    printf("-------------------------------\n");

    return 0;
}