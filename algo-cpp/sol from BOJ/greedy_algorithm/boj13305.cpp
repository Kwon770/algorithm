// https://www.acmicpc.net/problem/13305
// 13305 주유소
// Memory : 2800 KB
// Time : 0 ms
//
// 어떤게 Greedy 문제인지 확실히 알게해주는 문제이다.
// 메모이제이션을 활용한 DP 풀이법이 아닌, 도로를 차례로 나아가면서
// 이전의 최소 가격과 그 거리를 가지고 현재의 가격과 비교하여 최선의 가격을 찾는다.

#include <iostream>
#include <vector>
#include <climits>
#define endl "\n"
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> roads(n - 1), cities(n);
	for (int i = 0; i < n - 1; i++) cin >> roads[i];
	for (int i = 0; i < n; i++) cin >> cities[i];

	long long int prevPrice = INT_MAX, prevRoads = 0, totalPrice = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			totalPrice += prevRoads * prevPrice;
			break;
		}

		if (cities[i] < prevPrice) {
			totalPrice += prevRoads * prevPrice;
			prevPrice = cities[i];
			prevRoads = roads[i];
		} else {
			prevRoads += roads[i];	
		}
	}

	cout << totalPrice;
	return 0; 
}
