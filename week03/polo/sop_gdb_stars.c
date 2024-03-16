/* 
Please do not change the name of this file. 

Name (of all group members):
Date:
Program runs (yes or no, because): 
*/

#include <stdio.h>
#include <math.h>


void star(int n, double rint, double rext) {
    for (int i = 0; i < 5; i++) {             // Exercise 1. Observe the value of i
        double angle = M_PI * 2.0 / n * i;    // Exercise 1. Observe the value of angle
        double x = cos(angle) * rext;		  // Exercise 2. Replace the data type double of x by int
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
DEBUG SCRIPT 
gcc -ggdb sop_gdb_stars.c -o sop_gdb_stars_debug.out -lm
gdb ./sop_gdb_stars_debug.out 
(gdb) lay next
(gdb) list
(gdb) break 15
(gdb) run
(gdb) print i
(gdb) break 16
(gdb) continue
(gdb) print angle
(gdb) break 21
(gdb) continue
(gdb) print angle
*/