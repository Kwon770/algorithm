// https://www.acmicpc.net/problem/10757
// 10757 큰 수 A + B
//
// C, C++에서 못다루는 큰 수의 사칙연산에 관한 문제이다.
// 단순히 문자와 문자열을 통한 사칙연산을 구현하면 된다.
//
// 첫 풀이가 틀려서 길이에 대해 의심하면서 알아본 내용인데,
// string은 42억 자리, vector<char>은 그의 몇백배이므로 사이즈 걱정은 안해도되며,
// 이 문제에서는 string으로도 충분한 크기이다.
//
// 1. 두 숫자의 길이가 다를 경우, 인덱스를 별도로 관리해야한다.
// 2. 한 숫자가 혼자 짧은 경우, 계속 발생하는 받아올림의 계산도 구현해야한다.
// 이 두 가지만 조심하면 되다.
//
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> ans;
	string a, b;
	cin >> a >> b;
	string longest = a.length() < b.length() ? b : a;
	string shortest = a.length() < b.length() ? a : b;

	int overflowNumber = 0;
	for (int i = longest.length() - 1, j = shortest.length() - 1; i >= 0; i--, j--) {
		int longestNumber = longest[i] - '0';
		int shortestNumber = j >= 0 ? shortest[j] - '0' : 0;
		int result = longestNumber + shortestNumber + overflowNumber;
		overflowNumber = result / 10;
		result %= 10;
		longest[i] = result + '0';
	}

	if (overflowNumber != 0) cout << overflowNumber << longest;
	else cout << longest;
	return 0;
}
