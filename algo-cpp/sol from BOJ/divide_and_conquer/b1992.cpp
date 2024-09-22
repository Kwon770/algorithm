// https://www.acmicpc.net/problem/1992
// Divide_and_conquer(2), 쿼드트리
// NUMBER 1992

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'
vector<vector<char>> sq(65, vector<char>(65, 0));
string output;
char fInit = 0;
bool isSame = true;

int conquer(int xFrom, int xTo, int yFrom, int yTo) {
    char init = sq[xFrom][yFrom];
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
        output.push_back(init);
        if (!fInit)
            fInit = init;
        if (isSame && fInit != init)
            isSame = false;
    }
    return success;
}

void divide(int n, int xFrom, int xTo, int yFrom, int yTo) {
    int half = n / 2;
    output.push_back('(');
    for (int i = xFrom; i <= xTo; i += half)
        for (int o = yFrom; o <= yTo; o += half) {
            if (!conquer(i, i + half - 1, o, o + half - 1))
                divide(half, i, i + half - 1, o, o + half - 1);
        }
    output.push_back(')');
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
    divide(n, 1, n, 1, n);
    if (isSame)
        cout << fInit << endl;
    else
        cout << output << endl;
    return 0;
}