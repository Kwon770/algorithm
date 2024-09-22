#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, i, o, c;
void n7568() {
	scanf("%d", &n);
	int* arra = malloc(sizeof(int) * n);
	int* arrb = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) scanf("%d %d", &arra[i], &arrb[i]);
	for (i = 0; i < n; i++) {
		c = 0;
		for (o = 0; o < n; o++) {
			if (i == o) continue;
			if (arra[i] < arra[o] && arrb[i] < arrb[o]) c++;
		}
		printf("%d ", c + 1);
	}
}