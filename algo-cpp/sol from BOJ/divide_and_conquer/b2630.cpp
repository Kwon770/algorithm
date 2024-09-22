// https://www.acmicpc.net/problem/2630
// Divide_and_conquer(1), 색종이 만들기
// NUMBER 2630

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c

// 나눈 사각형안의 색깔이 같지 않으면 그 사각형을 다시 나누는 식으로 분할정복함.
// 사각형을 나누는 divide() 사각형안의 색깔을 확인하는 conquer() 함수
// conquer() 통해 색깔이 같지않음을 확인하면 divide()를 재귀함.

// 2차원 배열 선언과 매개변수로 전달하는 여러가지 방법
// https://www.notion.so/sckwon770/2-65dc95a360a446d5afd86c3a2783f226

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
vector<vector<bool>> sq(129, vector<bool>(129, 0));
int n, blue = 0, white = 0;

int conquer(int xFrom, int xTo, int yFrom, int yTo) {
    bool init = sq[xFrom][yFrom];
    bool success = true;
    for (int i = xFrom; i <= xTo; i++) {
        for (int o = yFrom; o <= yTo; o++) {
            if (init != sq[i][o]) {
                success = false;
                break;
            }
        }
        if (!success)
            break;
    }
    if (success) {
        if (init)
            blue++;
        else
            white++;
    }
    return success;
}

void divide(int n, int xFrom, int xTo, int yFrom, int yTo) {
    int half = n / 2;
    for (int i = xFrom; i <= xTo; i += half)
        for (int o = yFrom; o <= yTo; o += half)
            if (!conquer(i, i + half - 1, o, o + half - 1))
                divide(n / 2, i, i + half - 1, o, o + half - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++) {
            int temp;
            cin >> temp;
            sq[i][o] = temp;
        }
    divide(n, 1, n, 1, n);
    cout << white << endl;
    cout << blue << endl;
    return 0;
}