#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define swap(x,y) {int t = x; x = y; y = t; } 

void sort2108(int* arr, int l, int r)
{
	int left = l, right = r, p = arr[(l + r) / 2];
	while (left <= right)
	{
		while (p > arr[left]) left++;
		while (p < arr[right]) right--;

		if (left <= right)
		{
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	if (l < right) sort2108(arr, l, right);
	if (left < r) sort2108(arr, left, r);
}

int cArr[8001], qArr[500000], max, b;
void n2108()
{
	int i, n, t, index = -1;
	double r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		qArr[i] = t;
		r += t;
		//
		cArr[t + 4000]++;
	}
	sort2108(qArr, 0, n - 1);
	for (i = 0; i < 8001; i++) {
		if (max < cArr[i]) {
			max = cArr[i];
			t = i - 4000;
			b = 0;
		}
		else if (max == cArr[i]) {
			if (!b) {
				t = i - 4000;
				b = 1;
			}
		}
	}
	printf("%d\n", (int)round(r / n)); // 1
	printf("%d\n", qArr[n / 2]); // 2
	printf("%d\n", t); // 3
	printf("%d\n", qArr[n - 1] - qArr[0]); // 4
}