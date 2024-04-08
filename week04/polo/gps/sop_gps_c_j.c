/*
Please do not change the name of this file.

Name (of all group members): RICHOZ Julien & RICCI Paul
Date: 11.04.2024
Program runs (yes or no, because): Yes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A. Structure
struct GpsPoint
{
    double latitude;
    double longitude;
    float altitude;
    double x;
    double y;
    double z;
};

// B. Display a point
void display(struct GpsPoint *point)
{
    printf("%9.5f %9.5f %6.0f\n", point->latitude, point->longitude, point->altitude);
}

// C. Read a line
int readLine(char *line, struct GpsPoint *point)
{
    // Iteration through the line
    int strLength = strlen(line);
    int comaCount = 0;
    int firstComaPos = 0;
    int secondComaPos = 0;
    for (int i = 0; i < strLength; i++)
    {
        if (line[i] == ',')
        {
            comaCount++;
            if (firstComaPos == 0)
                firstComaPos = i;
            else
                secondComaPos = i;
        }
    }

    // Line is not valid
    if (comaCount != 2)
    {
        printf("Line is not valid !\n");
        return 0;
    }

    // Data extraction
    char *token;
    token = strtok(line, ",");
    point->latitude = atof(token);
    token = strtok(NULL, ",");
    point->longitude = atof(token);
    token = strtok(NULL, "\0");
    point->altitude = atof(token);
    return 1;
}

// D. Read an entire file
int readFile(char *fileName, struct GpsPoint *arrayToFill, int length)
{
    // Open the file
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
        return -1;
    // Read line by line
    int n = 0;
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL)
    {
        if (n >= length)
            break;
        int ok = readLine(buffer, &arrayToFill[n]);
        if (ok)
            n = n + 1;
    }
    // Close the file and return the number of lines read
    fclose(file);
    return n;
}

// E. Display the first 10 points
void display10Points(struct GpsPoint *points, char *filename)
{
    printf("%-25s first 10 points\n", filename);
    for (int i = 0; i < 10; i++)
    {
        printf("%-30s", "");
        display(&points[i]);
    }
}

// F. Altitude difference
int altDiff(struct GpsPoint *points, int start, int end)
{
    int b = points[end].altitude;
    int a = points[start].altitude;
    return b - a;
}

void printAltDiff(struct GpsPoint *points, char *filename, int start, int end)
{
    int altitudeDiff = altDiff(points, start, end);
    printf("%-25s altitude difference from points %d to %d = %d m\n",
           filename, start + 1, end + 1, altitudeDiff);
}

// G. Rise
int rise(struct GpsPoint *points, int start, int end)
{
    int rise = 0;
    for (int i = start + 1; i <= end; i++)
    {
        int altitudeDiff = altDiff(points, i - 1, i);
        if (altitudeDiff > 0)
            rise += altitudeDiff;
    }
    return rise;
}

void printRise(struct GpsPoint *points, char *filename, int start, int end)
{
    int rising = rise(points, start, end);
    printf("%-25s rise from points %d to %d = %d m\n",
           filename, start + 1, end + 1, rising);
}

// H. Function for Transformation in XYZ
void calculeXYZ(struct GpsPoint *point)
{
    // Struct GpsPoint has been modified
    // to hold x, y, z coordinates
    int radiusEarth = 6378100;
    double latRad = (point->latitude) * M_PI / 180.0;
    double lonRad = (point->longitude) * M_PI / 180.0;
    double alt = point->altitude;
    point->x = (radiusEarth + alt) * cos(latRad) * cos(lonRad);
    point->y = (radiusEarth + alt) * cos(latRad) * sin(lonRad);
    point->z = (radiusEarth + alt) * sin(latRad);
}

// H. Calculate X, Y, Z using the function above
void calculateXYZForAllPoints(struct GpsPoint *points, int nbPoints)
{
    for (int i = 0; i < nbPoints; i++)
    {
        calculeXYZ(&(points[i]));
    }
}

// I. Function for calculating distance
double distance(double dx, double dy, double dz)
{
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// I. Function for calculating distance between two points
double distancePoints(struct GpsPoint *a, struct GpsPoint *b)
{
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    return distance(dx, dy, dz);
}

// I. Calculate total distance using the function above
double totalDistance(struct GpsPoint *points, char *filename, int nbPoints)
{
    calculateXYZForAllPoints(points, nbPoints);
    double total = 0;
    for (int i = 1; i < nbPoints; i++)
    {
        total += distancePoints(&(points[i - 1]), &(points[i]));
    }
    printf("%-25s total distance = %.3f km\n", filename, total / 1000.);
    return total;
}

// J. Calculate maximum slope using the function above
int maxSlope(struct GpsPoint *points, char *filename, int nbPoints)
{
    calculateXYZForAllPoints(points, nbPoints);
    double maxSlope = 0;
    for (int i = 1; i < nbPoints; i++)
    {
        double altitudeDiff = altDiff(points, i - 1, i);
        double dist = distancePoints(&(points[i - 1]), &(points[i]));
        double slope = altitudeDiff / dist * 100;
        if (slope > maxSlope)
        {
            maxSlope = slope;
        }
    }
    maxSlope = round(maxSlope);
    printf("%-25s max slope = %.0f %%\n", filename, maxSlope);
    return maxSlope;
}

// MAIN-----------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    // D. Read the file
    struct GpsPoint *creuxPoints = malloc(1000 * sizeof(struct GpsPoint));
    int nbCreux = readFile("creux-du-van.csv", creuxPoints, 1000);
    struct GpsPoint *riedPoints = malloc(1000 * sizeof(struct GpsPoint));
    int nbRied = readFile("col-de-riedmatten.csv", riedPoints, 1000);
    struct GpsPoint *ulaganPoints = malloc(1000 * sizeof(struct GpsPoint));
    int nbUlagan = readFile("ulagan.csv", ulaganPoints, 1000);
    printf("\n");

    // E. Display the first 10 points
    display10Points(creuxPoints, "creux-du-van.csv");
    display10Points(riedPoints, "col-de-riedmatten.csv");
    display10Points(ulaganPoints, "ulagan.csv");
    printf("\n");

    // F. Difference in altitude
    printAltDiff(creuxPoints, "creux-du-van.csv", 0, nbCreux - 1);
    printAltDiff(riedPoints, "col-de-riedmatten.csv", 0, nbRied - 1);
    printAltDiff(ulaganPoints, "ulagan.csv", 0, nbUlagan - 1);
    printf("\n");

    // G. Rise
    printRise(creuxPoints, "creux-du-van.csv", 0, nbCreux - 1);
    printRise(riedPoints, "col-de-riedmatten.csv", 0, nbRied - 1);
    printRise(ulaganPoints, "ulagan.csv", 0, nbUlagan - 1);
    printf("\n");

    // H. Calculate X, Y, Z using the function above
    // I. Calculate total distance using the function above
    totalDistance(creuxPoints, "creux-du-van.csv", nbCreux);
    totalDistance(riedPoints, "col-de-riedmatten.csv", nbRied);
    totalDistance(ulaganPoints, "ulagan.csv", nbUlagan);
    printf("\n");

    // J. Calculate maximum slope using the function above
    maxSlope(creuxPoints, "creux-du-van.csv", nbCreux);
    maxSlope(riedPoints, "col-de-riedmatten.csv", nbRied);
    maxSlope(ulaganPoints, "ulagan.csv", nbUlagan);

    free(creuxPoints);
    free(riedPoints);
    free(ulaganPoints);

    return 0;
}
