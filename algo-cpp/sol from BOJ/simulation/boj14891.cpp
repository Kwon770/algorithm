// https://www.acmicpc.net/problem/14891
// 14891, 톱니바퀴
//
// 단순한 시뮬레이션 문제라 dequq를 이용하면 어렵지 않게 구현가능하다.
// 하지만  2 가지 놓칠 수 있는 점이 있는데,
// 1. 톱니바퀴의 회전가능 여부를 확인 톱니바퀴들이 하나도 돌아가지 않는 상태에서 해야한다.
// 의식의 흐름대로 구현하면서 한칸씩 돌려가며 회전여부를 확인하는 식으로 구현해버려서
// 테스트케이스에서부터 헤매었다.
// 2. 구현함수를 따로 빼면서 회전의 중심인 톱니바퀴 좌우로 확인해가는 것을 구현하다보니
// 회전의 중심인 본인 톱니바퀴를돌려주는 것을 까먹었다.
//
// 반례를 보면 바로 깨달을 수 있는 실수라, 문제를 파악한 후에는 바로 맞췄다.
//
#include <iostream>
#include <vector>
#include <deque>
#define endl "\n"
using namespace std;

#define leftSurface 6
#define rightSurface 2
vector<deque<int>> wheels(4, deque<int>(8));

void rotate(int idx, int dir) {
	if (dir == 1) {
		int tmp = wheels[idx].back();
		wheels[idx].pop_back();
		wheels[idx].push_front(tmp);
	} else {
		int tmp = wheels[idx].front();
		wheels[idx].pop_front();
		wheels[idx].push_back(tmp);
	}

}


void simulate(int idx, int dir) {
	int left = wheels[idx][leftSurface];
	int leftDir= dir;
	for (int i = idx; i > 0; i--) {
		if (left  == wheels[i - 1][rightSurface]) break;

		left = wheels[i - 1][leftSurface];
		leftDir *= -1;
		rotate(i - 1, leftDir);
	}

	int right = wheels[idx][rightSurface];
	int rightDir = dir;
	for (int i = idx; i < 3; i++) {
		if (right  == wheels[i + 1][leftSurface]) break;

		right = wheels[i + 1][rightSurface];
		rightDir *= -1;
		rotate(i + 1, rightDir);
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			wheels[i][j] = cin.get() - '0';
		}
		cin.get();

	}

	int k;
	cin >> k;
	while (k--) {
		int idx, dir;
		cin >> idx >> dir;

		simulate(idx - 1, dir);
		rotate(idx - 1, dir);
	}

	int score = 0;
	for (int i = 0; i < 4; i++) {
		if (wheels[i][0] == 0) continue;

		switch (i) {
			case 0:
				score += 1;
				break;
			case 1:
				score += 2;
				break;
			case 2:
				score += 4;
				break;
			case 3:
				score += 8;
				break;
		}
	}
	cout << score;

	return 0;
}
