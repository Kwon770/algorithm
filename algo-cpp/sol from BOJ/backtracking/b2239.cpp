// https://www.acmicpc.net/problem/2239
// 2239 스도쿠
//
// 스토쿠는 특별한 원리나 규칙이 있는게 아니라, 하나하나 대조하면서 풀어야 한다.
// 따라서 모든 경우의 수를 대조해보는 코드를 짜야한다.
// 하지만 브르투포스로 코드를 짜면 비료율적으로 반복되는 구간이 생겨 TLE가 발생한다.
// 최대한 최적화를 하기위해서는 문제가 되는 그 부분부터만 다시 대조하는 코드를 구현하는
// 백트래킹을 사용하면 된다.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

vector<vector<int>> sudoku(10, vector<int>(10));
bool isDone = false;

int getArea (int val) {
	val = (val - 1) / 3 + 1;
	if (val == 1) return 1;
	else if (val == 2) return 4;
	else return 7;
}

vector<int> checkDuplication(int row, int col) {
	vector<int> duplication;
	for (int i = 1; i <= 9; i++) {
		if (sudoku[row][i] != 0)
			duplication.push_back(sudoku[row][i]);

		if (sudoku[i][col] != 0) 
			duplication.push_back(sudoku[i][col]);
	}

	int colArea = getArea(col); 
	int rowArea = getArea(row);
	for (int dr = 0; dr < 3; dr++) {
		for (int dc = 0; dc < 3; dc++) {
			if (sudoku[rowArea + dr][colArea + dc] != 0)
				duplication.push_back(sudoku[rowArea + dr][colArea + dc]);	
		}
	}

	return duplication;
}

void recursion(int row, int col) {
	bool syncWithCol = true;
	for (int i = row; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (syncWithCol) {
				j = col - 1;
				syncWithCol = false;
				continue;
			}
			if (sudoku[i][j] != 0) continue;

			vector<int> duplication = checkDuplication(i, j);
			for (int newNum = 1; newNum <= 9; newNum++) {
				if (find(duplication.begin(), duplication.end(), newNum) != duplication.end()) continue;

				sudoku[i][j] = newNum;
				recursion(i, j + 1);

				if (isDone) return;

				sudoku[i][j] = 0;
			}
			if (sudoku[i][j] == 0) return;
		}
	}
	isDone = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			sudoku[i][j] = cin.get() - '0';
		}
		cin.get();
	}

	recursion(1, 1);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << sudoku[i][j];
		}
		cout << endl;
	}

	return 0;
}
