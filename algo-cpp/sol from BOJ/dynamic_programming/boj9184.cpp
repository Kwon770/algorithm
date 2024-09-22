// https://www.acmicpc.net/problem/9184
// 9184 신나는 함수 실행
//
// DP 문제의 감을 살리기 좋은 단순한 DP 문제이다
// Bottom top 방식을 좋아해서 풀려다가 전혀 구상되지 않아서
// Top Bottom 방식과 알고리즘 스터디에서 배운 종만북식 DP 풀이법을 적용해서 풀었다.
//
#include <cstring>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int cache[51][51][51];

int calculate(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return calculate(20, 20, 20);

	int& ret = cache[a][b][c];
	if (ret != -1) return ret;

	if (a < b && b < c) {
		ret = calculate(a, b, c - 1) + calculate(a, b - 1, c - 1) - calculate(a, b - 1, c);
	} else {
		ret = calculate(a - 1, b, c) + calculate(a - 1, b - 1, c) + calculate(a - 1, b, c - 1) 
			- calculate(a - 1, b - 1, c - 1);

	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(cache, -1, sizeof(cache));

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " <<  calculate(a, b, c) << endl;
	}
	return 0;
}
