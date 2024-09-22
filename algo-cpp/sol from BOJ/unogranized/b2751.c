#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(x,y) {int t = x; x = y; y = t; } 

void sort(int *arr, int l, int r)
{
	int left = l, right = r, p = arr[(l+r)/2];
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
	if (l < right) sort(arr, l, right);
	if (left < r) sort(arr, left, r);
}

void n2751()
{
	int c;
	scanf("%d", &c);
	int *arr = (int*)malloc(sizeof(int) * c);
	for (int i = 0; i < c; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, 0, c - 1);
	for (int i = 0; i < c; i++)
	{
		printf("%d\n", arr[i]);
	}
}