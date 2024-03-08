/*
Please do not change the name of this file.

Name (of all group members): Paul Ricci & Julien Richoz
Date: 03-08-2024
Program runs (yes or no, because): yes
*/

#include <stdio.h>
#include <math.h>

void star(int n, double rint, double rext);

int main(int argc, char *argv[])
{
	star(5, 50, 100);
	return 0;
}

void star(int n, double rint, double rext)
{
	double angleRad = (360.0 / n) * M_PI / 180.0;
	for (int i = 1; i <= n; i++)
	{
		printf("%d,%d\n", (int)(rext * cos(angleRad * i)), (int)(rext * sin(angleRad * i)));
		printf("%d,%d\n", (int)(rint * cos(angleRad * (i + 0.5))), (int)(rint * sin(angleRad * (i + 0.5))));
	}
}