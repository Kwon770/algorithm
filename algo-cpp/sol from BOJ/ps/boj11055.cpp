// https://www.acmicpc.net/problem/11055
// 11055 가장 큰 증가 부분 수열
// Memory : 2020 KB , Time : 0 ms
//
// 가장 긴 증가 부분 수열 문제와 굉장히 흡사한 문제이다. 이 종류 문제의 dp는 다음을 기억하면 된다.
// 1. 메모이제이션을 이용한 dp문제를 지나치게 최적화하여 풀려고 해선 안된다. 이 시리즈의 문제만 해도 n * (sigma 1~n)회 만큼 반복한다.
// n*n 에서 최적화한거니 꽤 큰 최적화이므로, 지나친 최적화에 얽매여서 풀이를 생각하지 말자.
// 2. 무엇을 최적화할지를 생각해보자. 증가 부분 수열이므로, 결국 어느 정도의 반복이 필요하다.
// 단, 증가이므로 0~i 만큼만 확인해보면 되고, 최대값만 묻고 어떤 원소들로 이루어져있는지는 묻지 않았으므로, 0~i 중에서 해당 인덱스에서
// 만들 수 있는 최대값을 찾아서 선택하면 된다.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

vector<int> nums, dp;
int n, maxVal = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    nums.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        int localSum = 0;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                localSum = max(localSum, dp[j]);
            }
        }
        dp[i] = nums[i] + localSum;
        maxVal = max(maxVal, dp[i]);
    }

    cout << maxVal;
    return 0;
}