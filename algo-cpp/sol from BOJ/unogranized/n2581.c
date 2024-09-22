#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check(int a)
{
	if (a == 1) return 0;
	else if (a == 2) return 1;
	else
	{
		for (int i = 2; i < a; i++)
		{
			if (a % i == 0) return 0;
		}
		return 1;
	}
}

void n2581()
{
	int m, n, total = 0, min = 10000;
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++)
	{
		if (check(i))
		{
			total += i;
			if (i < min) min = i;
		}
	}
	if (total == 0) printf("-1");
	else printf("%d\n%d", total, min);
}