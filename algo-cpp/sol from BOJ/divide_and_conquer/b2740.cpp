// https://www.acmicpc.net/problem/2740
// Divide_and_conquer(6), 행렬 곱셈
// NUMBER 2740

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c
// 행렬의 곱 https://www.notion.so/sckwon770/43c262912bf34e9ab4da3e11d5c64ec3

#include <iostream>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, A[101][101], B[101][101], C[101][101] = {{0}};
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= m; o++)
            cin >> A[i][o];
    cin >> m >> k;
    for (int i = 1; i <= m; i++)
        for (int o = 1; o <= k; o++)
            cin >> B[o][i];

    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= k; o++)
            for (int p = 1; p <= m; p++)
                C[i][o] += A[i][p] * B[o][p];

    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= k; o++)
            cout << C[i][o] << " ";
        cout << endl;
    }
    return 0;
}