#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define swap(a, b) {a = a + b; b = a - b; a = a - b;} 

void n4153()
{
	int a, b, c;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) break;
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		if (a * a + b * b == c * c) printf("right\n");
		else printf("wrong\n");
	}
}