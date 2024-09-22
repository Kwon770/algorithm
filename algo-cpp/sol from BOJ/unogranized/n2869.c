#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void n2869()
{ 
	printf("%d", 5 / 2);
	double a, b, v;
	scanf("%lf %lf %lf", &a, &b, &v);
	printf("%d", (int)ceil( (v-a)/(a-b) ) + 1);
}