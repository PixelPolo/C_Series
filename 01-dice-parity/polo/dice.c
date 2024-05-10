/* 
Please do not change the name of this file. 

Name (of all group members): Paul Ricci & Julien Richoz
Date: 23.02.2024
Program runs (yes or no, because): yes
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getDiceNumber() {
    double randomDomain = RAND_MAX + 1.0;
    return (int) ( random() / randomDomain * 6 ) + 1;
}

int main(int argc, char const *argv[])
{
    // init random
    srandom(time(NULL));

    // roll dices
    int a = getDiceNumber();
    int b = getDiceNumber();
    
    // print results
    printf("You got %d and %d\n", a, b);

    // tell if the gamer is a boss or not !
    if (a == 6 && b == 6) {
        printf("Good job !");
    } else if (a == b) {
        printf("Not bad...");
    } else {
        printf("Try again !");
    }
    return 0;
}

/*
    $ gcc dice.c -o dice -lm
    $ ./dice
*/
