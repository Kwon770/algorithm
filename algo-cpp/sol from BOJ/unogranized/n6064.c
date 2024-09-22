#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b)
{
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

void n6064()
{
	int c, m, n, x, y, max;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		if (m > n) max = lcm(m, n);
		else max = lcm(n, m);

		while (x != y && x <= max && y <= max)
		{
			if (x > y) y += n;
			else x += m;
		}
		printf("%d\n", x == y && x <= max ? x : -1);
	}
}