// https://www.acmicpc.net/problem/11055
// 11055 가장 큰 증가 부분 수열
// Memory : 2020 KB , Time : 0 ms
//
// ..

#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define ll long long
#define For(i, j, k) for (int i = j; i < (int)(k); i++)

char A[5][5] = {
        {' ', ' ', 'A', ' ', ' '},
        {' ', 'A', ' ', 'A', ' '},
        {'A', 'A', 'A', 'A', 'A'},
        {'A', ' ', ' ', ' ', 'A'},
        {'A', ' ', ' ', ' ', 'A'},
};

char B[5][5] = {
        {'B', 'B', 'B', ' ', ' '},
        {'B', ' ', ' ', 'B', ' '},
        {'B', 'B', 'B', ' ', ' '},
        {'B', ' ', ' ', 'B', ' '},
        {'B', 'B', 'B', ' ', ' '},
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int count = 2;
    char characters[2][5][5] = {A, B};

    a 44
    b 45
    c 46
    int index = (input - 'a')  = 2
    charcters[index];

    char board[5][5 * count];
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5 * count; col++) {
            char character[][] = characters[0];
            board[row][col] = character[row][col % 5];
        }
    }
    // A B

    // 출력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 * count; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    char tmp[5 * count];
    for (int col = 0; col < 5; col++) {
        tmp[col] = board[4][col];
    }
    for (int row = 4; row >= 0; row--) {
        for (int col = 0; col < 5; col++) {
            board[row - 1][col] = tmp[col];
            tmp[col] = board
        }
    }

    return 0;
}
