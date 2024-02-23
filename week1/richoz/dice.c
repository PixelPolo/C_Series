#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom(int max);
void dice();

int main(int argc, char * argv[]) {
    srandom(time(NULL));
    dice();
    return 0;
}

void dice(){
    int resultA = getRandom(6);
    int resultB = getRandom(6);

    if(resultA == resultB && resultA == 6){
        printf("Vous avez gagné!");
    } else if(resultA == resultB){
        printf("Pas mal!");
    } else {
        printf("Pas de chance!");
    }

    printf("\nLancé de dés : %d et %d\n", resultA, resultB);
}

int getRandom(int max){
    double randomDomaine = RAND_MAX + 1.0;
    return (int) (random() / randomDomaine * 6) + 1;
}