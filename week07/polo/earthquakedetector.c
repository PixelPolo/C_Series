#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int readFile(char *nameOfFile, double *tableToFill, int length)
{

    // Open the file
    FILE *file = fopen(nameOfFile, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: unable to open the file '%s'\n", nameOfFile);
        exit(1);
    }

    // Read line by line
    int n = 0;
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL)
    {
        if (n >= length)
            break;
        tableToFill[n] = atof(buffer);
        n = n + 1;
    }

    // Close the file and return the number of lines read
    fclose(file);
    return n;
}

/*
Calculate the energy of the earthquake,
i.e. the sum of the square values (∑x²)
between the beginning and the end.
*/
float calculateEnegy(double *earthquake, int start, int length)
{
    float sum = 0;
    for (int i = start; i < length; i++)
    {
        // printf("%f\n", earthquake[i]);
        sum += earthquake[i] * earthquake[i];
    }
    return sum;
}

/*
Find the beginning of the earthquake and display the number of the entry.
We say that there is an earthquake if the absolute value
of the signal exceeds 20.0 (You can try with other thresholds).
Look for the end of the earthquake, and display the number of the entry.
The earthquake is said to be over if 200 consecutive values are below the threshold.
Modify your program to detect several earthquakes.
For each earthquake, display its beginning, its length, and its energy.
*/
void findEarthquake(double *earthquake, int start, int length)
{
    // Comsmetic
    printf("\n");
    // local variables
    double threshold = 20.00;
    int startIndex = 0;
    int lastIndex = 0;
    int safeVal = 0;

    // Check for the first value above the threshold...
    for (int i = start; i < length; i++)
    {
        if (fabs(earthquake[i]) > threshold)
        {
            startIndex = i;
            break;
        }
    }

    // If no value above the threshold return. No earthquake...
    if (startIndex == 0)
        return;

    // An earthquake has been detected...
    printf("Earthquake started at index : %d\n", startIndex);

    // Iterate from the earthquake start index
    for (int j = startIndex + 1; j < length; j++)
    {
        // If under the threshold, increment the safe value counter
        if (fabs(earthquake[j]) < threshold)
        {
            safeVal++;
            if (safeVal == 200)
            {
                lastIndex = j;
                break;
            }
        }
        // If above the threshole, restart the safe value counter
        else
        {
            safeVal = 0;
        }
    }

    // Energy of the earthquake detected
    float energy = 0;

    // If the earthquake has finished...
    if (safeVal == 200)
    {
        // Print the last index
        printf("Earthquake finished at index : %d\n", lastIndex);
        // Compute the enery from start to last
        energy = calculateEnegy(earthquake, startIndex, lastIndex);
    }
    // The earthquake has been detected but not finished...
    else
    {
        // Print
        printf("Earthquake has not finished...\n");
        // Compute the energy from start to the max value of the file input
        energy = calculateEnegy(earthquake, startIndex, length);
    }

    // Print the energy
    printf("Energy of the earthquake : %.2f\n\n", energy);

    // Recursive find from lastIndex + 1 to check for another earthquake
    findEarthquake(earthquake, lastIndex + 1, length);
}

int main(int argc, char *argv[])
{
    double earthquake[11000];
    int length = readFile("earthquake-multiple", earthquake, 11000);
    findEarthquake(earthquake, 0, length);

    /*
    RESULTS :

    File : earthquake1

        Earthquake started at index : 400
        Earthquake finished at index : 942
        Energy of the earthquake : 236521.75

    File : earthquake2

        Earthquake started at index : 476
        Earthquake finished at index : 1114
        Energy of the earthquake : 227423.16

        Earthquake started at index : 1294
        Earthquake finished at index : 1494
        Energy of the earthquake : 9875.66

    File : earthquake3

        Earthquake started at index : 537
        Earthquake finished at index : 1568
        Energy of the earthquake : 312810.69

    File : eathquake multiple

        Earthquake started at index : 400
        Earthquake finished at index : 942
        Energy of the earthquake : 236521.75


        Earthquake started at index : 3936
        Earthquake finished at index : 4574
        Energy of the earthquake : 227423.16


        Earthquake started at index : 4754
        Earthquake finished at index : 4954
        Energy of the earthquake : 9875.66


        Earthquake started at index : 7453
        Earthquake finished at index : 8484
        Energy of the earthquake : 312810.69
    */

    return 0;
}