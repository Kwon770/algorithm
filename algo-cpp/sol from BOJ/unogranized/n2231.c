#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int i, t, m, n;

void n2231() {
	scanf("%d", &n);
	while (++i)
	{
		m = i; t = i;
		while (t) {
			m += t % 10;
			t /= 10;
		}
		if (m == n) {
			m = i;
			break;
		}
		else if (i > n) {
			m = 0;
			break;
		}
	}
	printf("%d", m == 0 ? 0 : m);
}