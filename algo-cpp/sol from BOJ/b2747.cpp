// https://www.acmicpc.net/problem/2747
// NUMBER 2747, 피보나치 수

#include <iostream>
using namespace std;
#define endl "\n"
int memo[46];

int pibo(int idx)
{
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    for (int i = 3; i <= idx; i++)
        memo[i] = memo[i - 1] + memo[i - 2];
    return memo[idx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << pibo(n) << endl;
    return 0;
}