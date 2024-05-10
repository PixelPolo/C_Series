/* 
Please do not change the name of this file. 

Name (of all group members): Ricci Paul & Richoz Julien
Date: 18.03.2024
Program runs (yes or no, because): YES
*/

#include <stdio.h>
#include <math.h>


void star(int n, double rint, double rext) {
    for (int i = 0; i < 5; i++) {               // Exercise 1. Observe the value of i
        int pi = (M_PI * 2.0);                  // Modif for B part
        double angle = pi / (n * i);      // Modif for B part
        // double angle = M_PI * 2.0 / n * i;       // Exercise 1. Observe the value of angle  
        double x = cos(angle) * rext;		    // Exercise 2. Replace the data type double of x by int
        double y = sin(angle) * rext;
        printf("%0.1f, %0.1f\n", x, y);

        angle = M_PI * 2.0 / n * (i + 0.5);   // Exercise 1. Observe the value of angle
        x = cos(angle) * rint;
        y = sin(angle) * rint;
        printf("%0.1f, %0.1f\n", x, y);
    }
}

int main(int argc, char * argv[]) {
	star(5, 50, 100);
    return 0;
}

/*

A. DEBUG SCRIPT

gcc -ggdb sop_gdb_stars.c -o debug.out -lm

// Observe the values of i at the end of line 14
// and angle at the end of lines 15 and 20

gdb ./debug.out
(gdb) break 15
(gdb) break 16
(gdb) break 21
(gdb) run
(gdb) print i       // $1 = 0
(gdb) c
(gdb) print angle   // $2 = 4.9406564584124654e-324
(gdb) c
(gdb) print angle   // $3 = 0
(gdb) exit

// Add also a watch on the value of i ...

gdb ./debug.out
(gdb) break 15
(gdb) run
(gdb) while i < 5
>watch i
>c
>end

// and x while running the loop...
// Witch watch x, it creates a mess

gdb ./debug.out
(gdb) break 24
(gdb) run
(gdb) print x       // $1 = 40.450849718747371
(gdb) c
(gdb) print x       // $2 = -15.450849718747367
(gdb) c
(gdb) print x       // $3 = -50
(gdb) c
(gdb) print x       // $4 = -15.450849718747378
(gdb) c
(gdb) print x       // $5 = 40.450849718747364
(gdb) c

B. LIMIT OF THE PROGRAM

gcc -ggdb sop_gdb_stars.c -o debug.out -lm
./debug.out 
nan, nan
40.5, 29.4
-73.7, 67.5
-15.5, 47.6
36.2, 93.2
-50.0, 0.0
69.7, 71.7
-15.5, -47.6
82.5, 56.5
40.5, -29.4

PROBLEM : The program does not crash on my machine !
So, no dump is generate...

*/