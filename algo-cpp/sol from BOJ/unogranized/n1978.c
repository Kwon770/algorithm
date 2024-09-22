#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void n1978()
{
	int a, b ,c = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		if (b == 1) continue;
		else if (b == 2) c++;
		else
		{
			c++;
			for (int o = 2; o < b; o++)
			{
				if (b % o == 0)
				{
					c--; 
					break;
				}
			}
		}
	}
	printf("%d", c);
}