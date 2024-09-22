#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct {
	char name[101];
	int age;
	int count
}array;
array sort[100001];
array arr[100001];

void merge10814(int left, int right, int mid, array* arr) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i].age <= arr[j].age) sort[k++] = arr[i++];
		else sort[k++] = arr[j++];
	}

	while (i <= mid) sort[k++] = arr[i++];
	while (j <= right) sort[k++] = arr[j++];

	for (k = left; k <= right; k++) arr[k] = sort[k];
}

void sort10814(int left, int right, array* arr) {
	int mid = (left + right) / 2;

	if (left < right) {
		sort10814(left, mid, arr);
		sort10814(mid + 1, right, arr);
		merge10814(left, right, mid, arr);
	}
}

void merge10814_2(int left, int right, int mid, array* arr) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i].count <= arr[j].count) sort[k++] = arr[i++];
		else sort[k++] = arr[j++];
	}

	while (i <= mid) sort[k++] = arr[i++];
	while (j <= right) sort[k++] = arr[j++];

	for (k = left; k <= right; k++) arr[k] = sort[k];
}

void sort10814_2(int left, int right, array* arr) {
	int mid = (left + right) / 2;

	if (left < right) {
		sort10814_2(left, mid, arr);
		sort10814_2(mid + 1, right, arr);
		merge10814_2(left, right, mid, arr);
	}
}

void n10814() {
	int n, i, b = 0, f, t;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %s", &(arr[i].age), arr[i].name);
		arr[i].count = i;
	}
	sort10814(0, n - 1, arr);
	for (i = 1; i < n; i++) {
		if (arr[i - 1].age == arr[i].age) {
			if (!b) {
				f = i - 1;
				b = 1;
			}
		}
		else {
			if (b) {
				t = i - 1;
				b = 0;
				sort10814_2(f, t, arr);
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}
}