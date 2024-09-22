// https://www.acmicpc.net/problem/1193
// 1193 분수찾기
//
// 규칙을 찾는게 해심인 문제.
// 1/1 부터 시작하여 우측으로 칸으로 진행하면서, 현재 칸 기준 좌하단 대각선에
// 목표 숫자가 있는지를 확인하는 과정을 거친다.
// 홀수칸일때와 짝수칸일때 좌하단대각선에 있는지 확인하는 방법이 달라진다.
// 구현하면서 생기는 예외사항을 처리하면서 풀어서 최선은 아닌 것 같지만
// 다른 풀이들보다 구현 느낌이 강해 이 코드가 더 깔끔하게 느껴짐
//
#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;
	if (x == 1) {
		cout <<  "1/1";
		return 0;
	}

	int colIdx = 2, curNumber = 2, addition = 0;
	while (true) {
		if (colIdx % 2) {
			if (x <= curNumber) break;

			curNumber++;
		} else {
			if (x >= curNumber && x < curNumber + colIdx) break;

			addition += 4;
			curNumber += addition;
		}
		colIdx++;
	}

	if (x == curNumber) cout << 1 << "/" << colIdx;
	else {
		int rowIdx = abs(x - curNumber);
		cout << rowIdx + 1 << "/" << colIdx - rowIdx;
	}

	return 0;
}
