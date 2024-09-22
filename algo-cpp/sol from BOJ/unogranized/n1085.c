#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void n1085()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if (x > w - x) x = w - x;
	if (x > y) x = y;
	if (x > h - y) x = h - y;
	printf("%d", x);
}