/* 
Please do not change the name of this file. 

Name (of all group members):
Date:
Program runs (yes or no, because): 
*/

#include <stdio.h>
#include <math.h>


void star(int n, double rint, double rext) {
    for (int i = 0; i < 5; i++) {
        double angle = M_PI * 2.0 / n * i;
        // Exercise 2. Replace the data type double of x by int
        double x = cos(angle) * rext;
        double y = sin(angle) * rext;
        printf("%0.1f, %0.1f\n", x, y);

        angle = M_PI * 2.0 / n * (i + 0.5);
        x = cos(angle) * rint;
        y = sin(angle) * rint;
        printf("%0.1f, %0.1f\n", x, y);
    }
}

int main(int argc, char * argv[]) {
	star(5, 50, 100);
    return 0;
}
