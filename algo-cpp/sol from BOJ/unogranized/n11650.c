#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define swap(x,y) {int t = x; x = y; y = t; } 

void sort11650(int* arrF, int* arrS, int l, int r)
{
	int left = l, right = r, p = arrF[(l + r) / 2];
	while (left <= right)
	{
		while (p > arrF[left]) left++;
		while (p < arrF[right]) right--;

		if (left <= right)
		{
			swap(arrF[left], arrF[right]);
			swap(arrS[left], arrS[right]);
			left++;
			right--;
		}
	}
	if (l < right) sort11650(arrF, arrS, l, right);
	if (left < r) sort11650(arrF, arrS, left, r);
}

void n11650()
{
	int n, f, t, b = 0, arrX[100000], arrY[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arrX[i], &arrY[i]);
	}
	sort11650(arrX, arrY, 0, n - 1);
	for (int i = 1; i < n; i++) {
		if (arrX[i - 1] == arrX[i]) {
			if (!b) {
				f = i - 1;
				b = 1;
			}
		}
		else {
			if (b) {
				t = i - 1;
				b = 0;
				sort11650(arrY, arrX, f, t);
			}
		}
	}
	if(b) sort11650(arrY, arrX, f, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arrX[i], arrY[i]);
	}
}