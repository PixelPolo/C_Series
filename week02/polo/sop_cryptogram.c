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

int main(int argc, char const *argv[])
{
    // Variables initialization
    int length = strlen(CRYPTOGRAM);
    int count = 17;
    int index = count;
    int c = 0;

    // Initialization of the answer array
    // No ASCII char is equal to -1...
    char answer[length];
    for (int i = 0; i < length; i++)
    {
        answer[i] = -1;
    }

    // Add the first letter at position 17
    answer[index] = CRYPTOGRAM[c++];

    // Iteration through the Cryptogram
    while (c < length)
    {
        // Skip slots with letters
        while (count != 0)
        {
            index++;
            if (answer[index % length] == -1)
            {
                count--;
            }
        }
        // Add letter and reset the counter
        answer[index % length] = CRYPTOGRAM[c++];
        count = 17;
    }

    // Print the answer
    answer[length] = '\0';
    printf("Answer : %s\n", answer);

    // Return exit code
    return 0;
}