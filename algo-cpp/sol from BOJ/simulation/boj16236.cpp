// https://www.acmicpc.net/problem/16236
// 16236 아기상어
// 
// 공간 탐색이 필요한 시뮬레이션 문제다.
// 아기상어의 경로를 공간 탐색, bfs를 통해 찾을 수 있다는 것을 깨닫는 것이 핵심이다.
// 
// 문제 핵심을 빨리 깨달았지만 2가지 실수로 시간이 상당히 오래걸렸는데
// 1. vector.resize() 는 공간 할당만 하고, 값을 초기화해주지 않는다.
// visited를 매번 초기화하는 과정에서 코드를 줄일려고 resize가 공간할당과 초기화를
// 동시에 해줄 것이라 생각하고 사용했는데, 아니였다.
// 2. 재귀를 한창 공부하다가 풀어서 그런지 dfs의 재귀 구조로 bfs를 구현했다.
// 이건 그냥 바보짓했다..
#include <climits>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define endl '\n'
using namespace std;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1}; 

int n, ans = 0, ateFish = 0, size = 2;
pair<int, int> shark;
vector<vector< int>> ocean;

int minDist;
vector<pair<int, int>> tmpFishes;
vector<vector<bool>> visited(21, vector<bool>(21, false));
bool checkPosition(int row, int col) {
	if (row < 1 || col < 1 || row > n || col > n || visited[row][col]) return false;

	visited[row][col] = true;
	int state = ocean[row][col];
	if (state != 0 && state != 9) {
		if (state < size) {
			tmpFishes.push_back(make_pair(row, col));
			return true;
		} else if (state > size) return false; 
	}
	return true;
}

void bfs() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = false;
		}
	}
	minDist = INT_MAX;
	tmpFishes.clear();
	queue<pair<int, int>> pathQueue;
	pathQueue.push(make_pair(shark.first, shark.second));

	int dist = 0, depth = 1, count = 0; 
	while (!pathQueue.empty()) {
		pair<int, int> curPath = pathQueue.front();
		pathQueue.pop();

		if (checkPosition(curPath.first, curPath.second)) {
			for (int i = 0; i < 4; i++) {
				pathQueue.push(make_pair(curPath.first+ dRow[i], curPath.second+ dCol[i]));
			}

		}

		count++;
		if (depth == count) {
			if (!tmpFishes.empty()) {
				minDist = dist;
				return;
			}		

			dist++;
			count = 0;
			depth = pathQueue.size();
		}

	}
}

pair<int, int> checkTarget() {
	bfs();
	int targetCount = tmpFishes.size();
	if (targetCount == 0) return make_pair(-1, -1);
	else if (targetCount == 1) return make_pair(tmpFishes.front().first, tmpFishes.front().second);
	else {
		pair<int, int> topLeftFish = tmpFishes.back();
		tmpFishes.pop_back();
		for (auto fish : tmpFishes) {
			if (topLeftFish.first > fish.first) topLeftFish = fish;
			else if (topLeftFish.first == fish.first) {
				if (topLeftFish.second > fish.second) topLeftFish = fish;
			}
		}

		return topLeftFish;
	}	
}

void simulate() {
	while (true) {
		pair<int, int> target = checkTarget();
		if (target.first == -1) return;

		ocean[shark.first][shark.second] = 0;
		shark = target;
		ocean[shark.first][shark.second] = 9;
		ateFish++;
		if (ateFish == size) {
			size++;
			ateFish = 0;
		}
		ans += minDist;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	ocean.resize(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int inp;
			cin >> inp;

			ocean[i][j] = inp;
			if (inp == 9) shark = make_pair(i, j);
		}
	}

	simulate();
	cout << ans;
	return 0;
}
