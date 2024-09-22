// https://www.acmicpc.net/problem/1780
// Divide_and_conquer(3), 종이의 개수
// NUMBER 1780

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c

// 1992, 2630 번의 응용

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
vector<vector<int>> sq(2188, vector<int>(2188, 0));
bool isClear = true;
int minuss = 0, zero = 0, pluss = 0, fInit;

int conquer(int xFrom, int xTo, int yFrom, int yTo) {
    int init = sq[xFrom][yFrom];
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
        if (init == -1)
            minuss++;
        else if (init == 0)
            zero++;
        else
            pluss++;
        if (isClear && fInit != init)
            isClear = false;
    }
    return success;
}

void divide(int n, int xFrom, int xTo, int yFrom, int yTo) {
    int tri = n / 3;
    for (int i = xFrom; i <= xTo; i += tri)
        for (int o = yFrom; o <= yTo; o += tri)
            if (!conquer(i, i + tri - 1, o, o + tri - 1))
                divide(tri, i, i + tri - 1, o, o + tri - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++)
            cin >> sq[i][o];
    fInit = sq[1][1];
    divide(n, 1, n, 1, n);
    if (isClear) {
        minuss = minuss > 0 ? 1 : 0;
        zero = zero > 0 ? 1 : 0;
        pluss = pluss > 0 ? 1 : 0;
    }
    cout << minuss << endl;
    cout << zero << endl;
    cout << pluss << endl;
    return 0;
}