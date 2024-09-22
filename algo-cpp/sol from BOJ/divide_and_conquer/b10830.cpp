// https://www.acmicpc.net/problem/10830
// Divide_and_conquer(7), 행렬 제곱
// NUMBER 10830

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define MOD 1000
vector<vector<long long>> Temp(6, vector<long long>(6, 0));
int n;

void matrix(vector<vector<long long>> &A, vector<vector<long long>> &B) {
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++)
            for (int p = 1; p <= n; p++) {
                Temp[i][o] += A[i][p] * B[p][o] % MOD;
            }

    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++) {
            A[i][o] = Temp[i][o] % MOD;
            Temp[i][o] = 0;
        }
}

void divide(long long _b, vector<vector<long long>> &Result, vector<vector<long long>> &Origin) {
    if (_b == 1)
        return;
    else {
        divide(_b / 2, Result, Origin);
        matrix(Result, Result);
        if (_b % 2)
            matrix(Result, Origin);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<long long>> Result(6, vector<long long>(6, 0));
    vector<vector<long long>> Origin(6, vector<long long>(6, 0));
    long long b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++) {
            cin >> Result[i][o];
            Origin[i][o] = Result[i][o];
        }

    if (b > 1)
        divide(b, Result, Origin);

    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= n; o++)
            cout << Result[i][o] % MOD << " ";
        cout << endl;
    }
    return 0;
}