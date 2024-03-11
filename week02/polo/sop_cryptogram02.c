/*
Please do not change the name of this file.

Name (of all group members): Paul Ricci & Julien Richoz
Date: 03-08-2024
Program runs (yes or no, because): yes
*/

#include <stdio.h>
#include <string.h>

#define CRYPTOGRAM "T-LS-AOS--EEOIOAAUENTUOLUILRPDSA-S.LUNV-ENEGT-T-E-NLLSBE"

static const int LENGTH = strlen(CRYPTOGRAM);
static const int GAP = 17;

void decrypt(char *cryptogram);

int main(int argc, char const *argv[])
{
    decrypt(CRYPTOGRAM);
    return 0;
}

void decrypt(char *cryptogram)
{
    // Declaration of the solution array
    char answer[LENGTH + 1];
    answer[LENGTH] = '\0';
    for (int i = 0; i < LENGTH; i++)
        answer[i] = -1;

    // Iteration with pointers
    char *answerptr = answer;
    while (*cryptogram)
    {
        int count = GAP;
        while (count != 0)
        {
            answerptr++;
            if (*answerptr == '\0')
                answerptr = answer; // Reset pointer
            if (*answerptr == -1)
                count--;
        }
        *answerptr = *cryptogram++; // Assign value
    }
    printf("Answer : %s\n", answer);
}