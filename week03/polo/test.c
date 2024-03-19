
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 5; i++)
    {
        double x = 10.0 / i;
        printf("%f\n", x);
    }
    return 0;
}

/*

CANNOT GENERATE A DUMP...

paulricci@wifi-unifr-134-133 polo % gcc -Wall test.c -o test.out -lm
paulricci@wifi-unifr-134-133 polo % ./test.out 
0.000000
10.000000
5.000000
3.000000
2.000000

*/
