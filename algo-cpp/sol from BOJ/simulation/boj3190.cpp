// https://www.acmicpc.net/problem/3190
// 3190 뱀
//
// 시뮬레이션 그자체인 문제다. (당연히 사과를 다먹어서 끝내는 문제인줋 알았지만
// 사망 시뮬레이션이다)
// deque를 잘 활용하면서 시뮬레이션을 직접하고 충돌처리만 해주면 풀리는 문제다.
// 신경쓸게 많아서 그렇지 어렵진 않다. 다만 오독할 여지가 있는 부분이 있어
// 푸는데 상당히 시간이 걸렸다.
// 
// 1. 뱀은 다음의 규칙을 따른다고 하면서 움직임의 규칙을 적어주었는데,
// 이는 규칙의 나열이아니라 순서대로 지켜야하는 이동의 순서다.
// 이를 정확히 캐치하지 못하면 뱀의 움직임 구현과 충돌처리간에 문제가 생긴다.
// 2. 방향전환은 시간 순서대로 주어주지만, 사과는 아무렇게나 준다.
// 이를 생각하지 않고 순서마냥 앞에서부터 순차적으로 확인하면 안된다.
//
#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#define endl '\n';
using namespace std;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};
int n, k, l;
deque<pair<int, int>> snake(1, make_pair(1, 1));

bool checkCollision() {
	int row = snake.back().first;
	int col = snake.back().second;
	snake.pop_back();
	if (row <= 0 || col <= 0 || row > n || col > n)
		return true;

	for (pair<int, int> part : snake) {
		cout << part.first << ":" << part.second << "~";
		if (row == part.first && col == part.second)
			return true;
	}
	cout << row << ":" << col << endl;

	snake.push_back(make_pair(row, col));
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> apples;
	vector<pair<int, char>> directions;
	cin >> n >> k;
	while (k--) {
		int r, c;
		cin >> r >> c;
		apples.push_back(make_pair(r, c));
	}	
	cin >> l;
	while (l--) {
		int x;
		char c;
		cin >> x >> c;
		directions.push_back(make_pair(x, c));
	}

	// 0 top 1 right 2 bottom 3 left
	int curRow = 1, curCol = 1, dir = 1, time = 0;
	auto nextDirection = directions.begin();
	while (true) {	
		time++;

		curRow += dRow[dir];
		curCol += dCol[dir];	

		snake.push_back(make_pair(curRow, curCol));
		if (checkCollision()) break;

		bool isAteApple = false;
		for (auto iter = apples.begin(); iter != apples.end(); iter++) {
			if (curRow == (*iter).first && curCol == (*iter).second) {
				apples.erase(iter);
				isAteApple = true;
				break;
			}
		}
		if (!isAteApple) snake.pop_front();

		if ((*nextDirection).first == time) {
			if ((*nextDirection).second == 'L') dir--;
			else dir++;
			dir = dir == 4 ? 0 : dir;
			dir = dir == -1 ? 3 : dir;
			nextDirection++;
		}	
		cout << snake.back().first << "/" << snake.back().second  << "<" << time << " ";

	} 
	cout << time;
	return 0;
}
