// https://www.acmicpc.net/problem/1699
// 1699 제곱수의 합
//
// 어떤 식으로 캐싱을 할지 점화식을 찾는 것이 핵심인 문제다.
// 최대의 제곱수를 이용해서 Top - Bottom 방식으로 타고내려가는 방식이
// 처음 보이고 쉽기 때문에 그렇게 풀기 쉬운데, 예외가 있어서 틀린다.
// 43의 경우, 25 + 9 + 9 를 통해 3이 나와야 하지만,
// 최대 제곱수 풀이는 36 + 4 + 1 + 1 + 1으로 5가 나온다.
//
// 따라서 Bottom - Top 방식으로 풀 것이며 흔히 하는 늘 최적해를 유지하는 식으로 푼다.
// 단 어느 제곱수가 사용될지 모르므로, 매번 가능한 모든 제곱수를 이용해서 계산한다.
// 가능한 최대값은 1로 가득차는 경우 이므로, 이를 디폴트값으로 설정한다.
// cache[i] = min(cache[i], cache[i - j*j] + 1);
//
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> cache(100001);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cache[i] = i;
		for (int j = 1; j * j <= i; j++) {
			cache[i] = min(cache[i], cache[i - j*j] + 1);
		}
	}

	cout << cache[n];
	return 0;
}
