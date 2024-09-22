// https://www.acmicpc.net/problem/1654
// Binaray Search(3), 랜선 자르기
// NUMBER 1654

// Binaray Search, https://www.notion.so/sckwon770/Binaray-Search-b50720f0f2df4aa486cf6b3b4797b6d2

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

// 주어지는 숫자들은 int 의 최댓값보다 같거나 작은 값임
// 따라서 mid 값을 구하기 위해 더하는 과정에서 오버플로우가 나므로 long long 을 사용

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    long long left = 1,
              right = *max_element(input.begin(), input.end()),
              max = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += input[i] / mid;
        }
        if (cnt >= k) {
            max = max > mid ? max : mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << max << endl;
    return 0;
}