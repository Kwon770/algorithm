#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000001];
void n1929()
{
	int a, b, t;
	scanf("%d %d", &a, &b);
	arr[1] = 1;
	for (int i = 2; i <= b; i++)
	{
		if (!arr[i])
		{
			for (int o = 2; o <= b; o++)
			{
				t = i * o;
				if (t > b) break;
				arr[t] = 1;
			}
		}
	}
	for (int i = a; i <= b; i++) if (!arr[i]) printf("%d\n", i);
}