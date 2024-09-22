#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define swap(x,y) {int t = x; x = y; y = t; } 

void sort11651(int* arrF, int* arrS, int l, int r)
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
	if (l < right) sort11651(arrF, arrS, l, right);
	if (left < r) sort11651(arrF, arrS, left, r);
}

void n11651()
{
	int n, f, t, b = 0, arrX[100000], arrY[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arrX[i], &arrY[i]);
	}
	sort11651(arrY, arrX, 0, n - 1);
	for (int i = 1; i < n; i++) {
		if (arrY[i - 1] == arrY[i]) {
			if (!b) {
				f = i - 1;
				b = 1;
			}
		}
		else {
			if (b) {
				t = i - 1;
				b = 0;
				sort11651(arrX, arrY, f, t);
			}
		}
	}
	if (b) sort11651(arrX, arrY, f, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arrX[i], arrY[i]);
	}
}