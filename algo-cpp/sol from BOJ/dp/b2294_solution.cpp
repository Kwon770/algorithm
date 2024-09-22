// https://www.acmicpc.net/problem/2294
// 2294 동전 2
//
// b2294.cpp 풀이에서 최대한 최적화한 풀이
//
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;

const int MAX = 10000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> coins;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		coins.insert(inp);
	}

	vector<int> cache(10001, MAX);
	cache[0] = 0;
	for (int coin : coins) {
		for (int i = coin; i <= k; i++) {
			cache[i] = min(cache[i], cache[i - coin] + 1);
		}
	}

	cout << (cache[k] == MAX ? -1 : cache[k]);
	return 0;
}
