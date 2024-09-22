#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct {
	char string[51];
	int length;
}array;
array sort[20000];
array arr[20000];

void merge1181(int left, int right, int mid, array* arr) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i].length < arr[j].length) sort[k++] = arr[i++];
		else if (arr[i].length == arr[j].length) {
			if (strcmp(arr[i].string, arr[j].string) < 0) sort[k++] = arr[i++];
			else sort[k++] = arr[j++];
		}
		else sort[k++] = arr[j++];
	}

	while (i <= mid) sort[k++] = arr[i++];
	while (j <= right) sort[k++] = arr[j++];

	for (k = left; k <= right; k++) arr[k] = sort[k];
}

void sort1181(int left, int right, array* arr) {
	int mid = (left + right) / 2;

	if (left < right) {
		sort1181(left, mid, arr);
		sort1181(mid + 1, right, arr);
		merge1181(left, right, mid, arr);
	}
}


n1181() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i].string);
		for (int j = 0; j < 51; j++) arr[i].length = strlen(arr[i].string);
	}
	sort1181(0, n - 1, arr);

	for (int i = 0; i < n; i++) {
		if (i == 0)
			printf("%s\n", arr[i].string);
		else {
			if (strcmp(arr[i - 1].string, arr[i].string) != 0) {
				printf("%s\n", arr[i].string);
			}
		}
	}

}