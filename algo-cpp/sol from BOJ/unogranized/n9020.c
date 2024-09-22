#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10001];

int set()
{
	arr[1] = 1;
	int t;
	for (int i = 2; i <= 10000; i++)
	{
		if (!arr[i])
		{
			for (int o = 2; o <= 10000; o++)
			{
				t = i * o;
				if (t > 10000) break;
				arr[t] = 1;
			}
		}
	}
}

void n9020()
{
	set();
	int c, n, i;
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &n);
		for (i = n/2; i >= 2; i--) if (!arr[i] && !arr[n - i]) break;
		printf("%d %d\n", i, n -i);
	}
}