#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char arr[51][51], a, b;
int n, m, i, o, t, r = 2500, ar = 0, br = 0;

int count(int x, int y) {
	ar = 0, br = 0;
	a = arr[x][y];
	b = a == 'W' ? 'B' : 'W';
	for (i = x; i <= x+7; i++) {
		for (o = y; o <= y+7; o += 2) {
			if (a != arr[i][o]) ar++;
			else br++;
		}
		for (o = y+1; o <= y+7; o += 2) {
			if (b != arr[i][o]) ar++;
			else br++;
		}
		a = a + b, b = a - b, a = a - b;
	}
	return ar > br ? br : ar;
}

void n1018()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) for (o = 1; o <= m; o++) {
			scanf(" %c", &arr[i][o]);
	}
	for (int i = 1; i + 7 <= n; i++) for (int o = 1; o + 7 <= m; o++) {
		t = count(i, o);
		if (r > t) r = t;
	}
	printf("%d", r);
}