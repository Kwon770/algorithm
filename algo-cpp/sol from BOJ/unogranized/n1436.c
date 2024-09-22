#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void n1436()
{
	int n, number = 665, t, b = 0;
	scanf("%d", &n);
	while (n) {
		number++;
		t = number;
		b = 0;
		while (t) {
			if (t % 1000 == 666) {
				b = 1;
				break;
			}
			t /= 10;
		}
		if (b) n--;
	}
	printf("%d", number);
}