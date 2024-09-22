// https://www.acmicpc.net/problem/2751
// 2751 수 정렬하기 2
//
// 힙정렬 혹은 병합정렬 (O( log n ) 복잡도인 정렬을 사용하여야 하는 문제이다.
// 참고한 자료
// https://gmlwjd9405.github.io/2018/05/10/algorithm-heap-sort.html
//
#include <iostream>
#define endl '\n'
using namespace std;

int n, heap[1000001], heapSize = 0;

void insertHeap(int element) {
	int idx = ++heapSize;
	while((idx != 1) && (element > heap[idx / 2])) {
		heap[idx] = heap[idx / 2];
		idx /= 2;
	}
	heap[idx] = element;
}

void deleteHeap() {
	int parent = 1, child = 2;
	int tmp = heap[heapSize];
	heap[heapSize--] = heap[parent];

	while (child <= heapSize) {
		if ( (child < heapSize) && (heap[child] < heap[child + 1]) ) {
			child++;
		}

		if (tmp >= heap[child]) break;

		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}

	heap[parent] = tmp;
}

void sortHeap() {
	for (int i = n; i > 0; i--) {
		deleteHeap();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		insertHeap(inp);
	}

	sortHeap();

	for (int i = 1; i <= n; i++) {
		cout << heap[i] << endl;
	}

	return 0;
}
