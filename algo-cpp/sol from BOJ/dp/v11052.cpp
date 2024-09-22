#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX = 1001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> packs(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> packs[i];
	}

	vector<vector<int>> cache(n + 1, vector<int>(n + 1, MAX));
	for (int i = 1; i <= n; i++) {
		cache[1][i] = packs[1] * i;
	}
	int ans = cache[1][n];

	for (int i = 2; i <= n; i++) {
		for (int curCount = i; curCount <= n; curCount += i) {
			if (curCount - i > 0 && cache[i - 1][curCount - i] != MAX) {
				cache[i][curCount] = max(i * curCount, cache[i - 1][curCount - i] + i);
			} else {
				cache[i][curCount] = i * curCount;
			}
			ans = max(ans, cache
		}
	}

	cout << 
	return 0;
}
