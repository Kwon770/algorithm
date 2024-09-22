#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void n1002()
{
	int t, x1, y1, r1, x2, y2, r2, dr, sr, c;
	double d;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		dr = abs(r1 - r2), sr = r1 + r2, d = sqrt((double)pow(x2 - x1, 2) + (double)pow(y2 - y1, 2));

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) c = -1;
			else c = 0;
		}
		else {
			if (dr < d && d < sr) c = 2;
			else if (dr == d || sr == d) c = 1;
			else if (sr < d || d < dr) c = 0;
		}
		printf("%d\n", c);
	}
}