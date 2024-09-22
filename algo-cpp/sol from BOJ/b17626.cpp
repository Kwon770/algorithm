// https://www.acmicpc.net/problem/17626
// NUMBER 17626, Foue Squares

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 987654321
using namespace std;
 
int main()
{
	int memo[50001];
	memset(memo, 0, sizeof(memo));
    memo[0] = 0;
	memo[1] = 1;
 
    vector<int> Squares;
	for (int i = 1; i < 225; ++i) {
		Squares.push_back(i * i);
	}

    int n;
    cin >> n;
 
	for (int i = 2; i <= n; ++i) {
		int minNum = MAX;
 
		for (int j = 0; Squares[j] <= i; ++j) {
			int tmp = i - Squares[j];
			minNum = min(minNum, memo[tmp]);
		}
 
		memo[i] = minNum + 1;
	}
 
	cout << memo[n] << endl;
 
	return 0;
}	