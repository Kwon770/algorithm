#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void n2798()
{
	int n, m, arr[100], t, r = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int a = 0; a < n - 2; a++)
	{
		for (int b = a + 1; b < n - 1; b++)
		{
			for (int c = b + 1; c < n; c++)
			{
				t = arr[a] + arr[b] + arr[c];
				if (t <= m && m - r > m - t) r = t;
			}
		}
	}
	printf("%d", r);
}