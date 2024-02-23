/* 
Please do not change the name of this file. 

Name (of all group members): Paul Ricci & Julien Richoz
Date: 23.02.2024
Program runs (yes or no, because): Yes
*/

#include <stdio.h>
#include <stdlib.h>

void parity();

int main(int argc, char * argv[]) {
    parity();
    return 0;
}

void parity(){
    int sum = 0;
    for(int i = 0; i <= 20; i += 2){
        sum += i;
        printf("Pair : %d\n", i);
    }
    printf("The sum is %d", sum);
}