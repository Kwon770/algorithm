// https://www.acmicpc.net/problem/2293
// Dynamic Programming2 (1), 동전1
// NUMBER 2293

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c
// 동적 프로그래밍이라고 무조건 재귀적으로 푸는 것이 아니고, 메모제이션을 잘 활용해야함

#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, coins[101], memo[10001];
    fill_n(memo, 10001, 0);
    memo[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    for (int i = 0; i < n; i++)
        for (int o = coins[i]; o <= k; o++)
            memo[o] += memo[o - coins[i]];

    cout << memo[k] << endl;
    return 0;
}