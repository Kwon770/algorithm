// https://programmers.co.kr/learn/courses/30/lessons/86491?language=cpp
// 8주차_최소직사각형
//

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int solution(vector<vector<int>> sizes) {
    int maxVal = INT_MIN, minVal = INT_MIN;

    for (auto wallet : sizes) {
        int big = max(wallet[0], wallet[1]);
        int small = min(wallet[0], wallet[1]);

        maxVal = max(maxVal, big);
        minVal = max(minVal, small);
    }

    return maxVal * minVal;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> a = {{1,2}, {3,4}};
    cout << solution(a);
    return 0;
}