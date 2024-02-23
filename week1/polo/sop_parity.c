/* 
Please do not change the name of this file. 

Name (of all group members): Paul Ricci & Julien Richoz
Date: 23.02.2024
Program runs (yes or no, because): Yes
*/

#include <stdio.h>

int parity(int size);

int main(int argc, char const *argv[])
{
    printf("Sum = %d", parity(20));
    return 0;
}

int parity(int size) {
    int sum = 0;
    for (int i = 0; i <= size; i += 2) {
        sum += i;
    }
    return sum;
}