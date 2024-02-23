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