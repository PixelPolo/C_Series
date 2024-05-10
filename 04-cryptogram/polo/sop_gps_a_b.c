/*
Please do not change the name of this file.

Name (of all group members): Paul Ricci & Julien Richoz
Date: 03-08-2024
Program runs (yes or no, because): yes
*/

#include <stdio.h>

// A. Structure
// your code here
struct GpsPoint
{
    double latitude;
    double longitude;
    float altitude;
};

// B. Display a point
// your code here
void display(struct GpsPoint *point)
{
    printf("GPSPoint { Lat : %f | Lon : %f | Alt : %f\n",
           (*point).altitude,
           // point->altitude,
           point->latitude,
           point->altitude);
}

// ***** main *****
int main(int argc, char *argv[])
{
    // Test display
    struct GpsPoint point = {45.97639, 7.65833, 4478};
    display(&point);

    return 0;
}