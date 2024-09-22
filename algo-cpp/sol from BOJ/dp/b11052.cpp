// https://www.acmicpc.net/problem/11052
// 11052 카드 구매하기
//
// 냅색 문제와 비슷한 유형을 연속해서 풀어선지, 냅색문제의 캐싱과 비슷하게 해보려는
// 시도를 하다가, 결국 실패한 문제이다.
// N개의 카드를 구매하기 위한 경우의 수는 매우 다양한 카드팩을 고를 수 있기 때문에,
// 이를 전부 캐싱해야한다는 생각에 2차원 배열로 캐싱하는데 열중한 것 같다.
//
// 스터디에서 아이디어를 설명들은 후, 각 개수의 최적값을 구하기위해 가능한 경우의 수를 정리해보니
// 1차원 배열로 아주 간단히 정리가 되었다. 2차원 배열 캐싱을 고집할 필요가 없고
// 테스트케이스를 분석하면서 패턴을 살펴보는 과정이 꼭 거쳐야겠다.
//
#include <iostream>
#include <cmath>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> cache(n + 1);
	vector<int> packs(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> packs[i];
	}

	cache[1] = packs[1];
	for (int i = 2; i <= n; i++) {
		cache[i] = packs[i];
		for (int j = 1; j < i; j++) {
			cache[i] = max(cache[i], cache[j] + packs[i - j]);
		}
	}

	cout << cache[n];

	return 0;
}
