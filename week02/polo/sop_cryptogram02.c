/*
Please do not change the name of this file.

Name (of all group members): Paul Ricci & Julien Richoz
Date: 03-08-2024
Program runs (yes or no, because): yes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRYPTOGRAM "T-LS-AOS--EEOIOAAUENTUOLUILRPDSA-S.LUNV-ENEGT-T-E-NLLSBE"

static const int LENGTH = strlen(CRYPTOGRAM); // 56
static const int GAP = 17;

void decrypt(char *cryptogram);
void decrypt2(char *cryptogram);

int main(int argc, char const *argv[])
{
    decrypt(CRYPTOGRAM);
    decrypt2(CRYPTOGRAM);
    return 0;
}

/* BUG HERE */
void decrypt(char *cryptogram)
{
    char *sol = (char *)malloc(LENGTH * sizeof(char));
    char *origin = sol;
    while (*cryptogram)
    {
        int count = GAP;
        while (count != 0)
        {
            sol++;
            if (sol == origin + LENGTH)
            {
                sol = origin;
            }
            if (!*sol)
            {
                count--;
            }
        }
        *sol = *cryptogram++;
        printf("Solution : %s\n", sol);
    }
    printf("Solution : %s\n", sol);
    free(origin);
}

/* OK */
void decrypt2(char *cryptogram) {
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
