/*
Please do not change the name of this file.

Name (of all group members): Paul Ricci & Julien Richoz
Date: 03-08-2024
Program runs (yes or no, because): yes
*/

#include <stdio.h>
#include <string.h>

// CRYPTOGRAM SYMBOLIC CONSTANT
#define CRYPTOGRAM "T-LS-AOS--EEOIOAAUENTUOLUILRPDSA-S.LUNV-ENEGT-T-E-NLLSBE"

// Static variables
static const int LENGTH = strlen(CRYPTOGRAM);
static const int GAP = 17;

// Function prototype
void decrypt(char *cryptogram);

int main(int argc, char const *argv[])
{
    decrypt(CRYPTOGRAM);
    // Return exit code
    return 0;
}

void decrypt(char *cryptogram)
{
    // Initialization of the answer array
    char answer[LENGTH];
    for (int i = 0; i <= LENGTH; i++)
        answer[i] = '\0';

    // Add the first letter at position 17
    int c = 0;
    answer[GAP] = cryptogram[c++];

    // Iteration through the Cryptogram
    int index = GAP;
    while (c < LENGTH)
    {
        // Skip slots with letters or count-- if not letters
        int count = GAP;
        while (count != 0)
        {
            index++;
            // 56 % 56 = 0 (going back to index 0)
            if (answer[index % LENGTH] == '\0')
            {
                count--;
            }
        }
        // Add letter and reset the counter
        answer[index % LENGTH] = cryptogram[c++];
    }
    printf("Answer : %s\n", answer);
}