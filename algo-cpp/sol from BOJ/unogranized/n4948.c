#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[246913];

int check1(int n)
{
	int t, m = 2 * n, c = 0;
	for (int i = 2; i <= m; i++)
	{
		if (!arr[i])
		{
			for (int o = 2; o <= m; o++)
			{
				t = i * o;
				if (t > m) break;
				arr[t] = 1;
			}
		}
	}
	for (int i = n + 1; i <= m; i++) if (!arr[i]) c++;
	return c;
}

void n4948()
{
	arr[1] = 1;
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		printf("%d\n", check1(n));
	}
}