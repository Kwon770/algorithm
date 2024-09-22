// https://www.acmicpc.net/problem/2294
// 2294 동전 2
//
// 냅색문제처럼 2차원 배열로 캐싱하였다.  
// 각 자리 숫자까지 확인했을 때, k 원을 만들기 위해 필요한 동전의 개수를 캐싱하였다.
// 
// 동전이 불규칙적으로 중복되어 입력될 수 있다는 조건이 있어서, unordered_set으로 동전을 입력받았다.
// set은 insert가 O(logN)인데, 정렬은 필요가 없으므로 unordered_set을 사용하여 O(1)의 복잡도를 가진다.
//
// 문제를 다 풀었지만 계속해서 틀렸는데, 캐싱의 최대값을 INT_MAX를 사용한 것이 문제였다.
// 31번줄, 두 값의 최소값을 캐싱하는 과정에서 cache[idx][j - *iter] + 1 부분에서
// INT_MAX + 1 을 하게되어 undefined behavior이다.
// 따라서 의도되지 않는 값이 비교가 되므로, 실제 정확한 MAX 값을 설정하였다.
//
// 이 풀이에선 냅색형식으로 2차원 배열 캐싱을 하였지만, 값을 캐싱하는 과정의 규칙을 단순화하면
// 1차원 배열로 캐싱이 가능하다. ~/b2294_solution.cpp
//
#include <iostream>
#include <vector>
#include <unordered_set>
#define endl '\n'
using namespace std;

const int MAX = 10000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<int> coins;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		coins.insert(inp);
	}

	vector<vector<int>> cache(101, vector<int> (10001, MAX));
	int idx = 1;
	for (auto iter = coins.begin(); iter != coins.end(); iter++, idx++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0) {cache[idx][j] = 0; continue;}

			if (j - *iter >= 0) {
				cache[idx][j] = min(cache[idx - 1][j], cache[idx][j - *iter] + 1);
			} else {
				cache[idx][j] = cache[idx - 1][j];
			}
		}
	}

	int last = idx - 1;
	cout << (cache[last][k] == MAX ? -1 : cache[last][k]);
	return 0;
}
