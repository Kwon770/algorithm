#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, t, arr[100001];
void n10989()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		arr[t]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) continue;
		for (int o = 0; o < arr[i]; o++) printf("%d\n", i);
	}
}