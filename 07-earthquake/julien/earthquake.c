#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QUAKE_THRE 20
#define SAFE_ITERATION 200


int readFile(char * nameOfFile, double * tableToFill, int length) {
    // Open the file
    FILE * file = fopen(nameOfFile, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: unable to open the file '%s'\n", nameOfFile);
        exit(1);
    }

    // Read line by line
    int n = 0;
    char buffer[100];
    while (fgets(buffer, 100, file) != NULL) {
        if (n >= length) break;
        tableToFill[n] = atof(buffer);
        n = n + 1;
    }

    // Close the file and return the number of lines read
    fclose(file);
    return n;
}

int computeLength(int firstHit, int lastHit){
    return lastHit - firstHit;
}

int main(int argc, char * argv[]) {
    double earthquake[11000];
    int length = readFile("earthquake-multiple", earthquake, 11000);
    int earthquakeStartIndex = -1; // -1 means no active earthquake
    int safeIteration = 0;
    int numberEarthquake = 1;
    int size = 0;
    double energy = 0;

    for (int i = 0; i < length; i++) {
        if (fabs(earthquake[i]) >= QUAKE_THRE) {
            if (earthquakeStartIndex == -1) {
                earthquakeStartIndex = i;
                printf("Start Earthquake n°%d - first hit at i=%d\n", numberEarthquake, i);
            }
            energy += fabs(earthquake[i]) * 2;
            safeIteration = 0;
        } else {
            safeIteration++;
        }

        if (safeIteration >= SAFE_ITERATION && earthquakeStartIndex != -1) {
            size = computeLength(earthquakeStartIndex, i);
            printf("End of Earthquake n°%d - last hit at i=%d \n", numberEarthquake, i);
            printf("---> INFORMATIONS:: \nLength: %d // \nEnergy: %f, \nratioPower=%f\n\n", size, energy, energy/size);

            numberEarthquake++;
            earthquakeStartIndex = -1; // Reset for next earthquake
            energy = 0;
            size = 0;
        }
    }
    return 0;
}

