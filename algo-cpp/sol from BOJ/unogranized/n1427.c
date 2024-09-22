#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define swap(x,y) {int t = x; x = y; y = t; } 

void sort1427(int* arr, int l, int r)
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
	if (l < right) sort1427(arr, l, right);
	if (left < r) sort1427(arr, left, r);
}

void n1427()
{
	int n, i = -1, arr[10];
	scanf("%d", &n);
	while (n) {
		i++;
		arr[i] = n % 10;
		n /= 10;
	}
	sort1427(arr, 0, i);
	while (i >= 0) {
		printf("%d", arr[i]);
		i--;
	}
}