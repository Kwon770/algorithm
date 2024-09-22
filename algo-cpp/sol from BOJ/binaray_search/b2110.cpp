// https://www.acmicpc.net/problem/2110
// Binaray Search(5), 공유기 설치
// NUMBER 2110

// Binaray Search, https://www.notion.so/sckwon770/Binaray-Search-b50720f0f2df4aa486cf6b3b4797b6d2

// 확인할 거리의 선택은 이진탐색을 통해서 복잡도를 줄이고,
// 해당 거리가 유효하는지는 isPossible을 통해 집마다 확인을 함.
// 공유가가 설치된 이전 집과 현재의 집의 거리가 선택한 거리 이상이여야 하며, 이런 집들이 목표보다 많아야 유효함.

// 맨 처음과 맨 마지막에 공유기를 설치하고 시작하는게 늘 최선이 아닐 수도 있음을 명심

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n, c, temp;
vector<int> houses;

bool isPossible(int dist) {
    int cnt = 1;
    int prev = houses[0];
    for (int i = 1; i < n; i++) {
        if (houses[i] - prev >= dist) {
            cnt++;
            prev = houses[i];
        }
    }

    if (cnt >= c)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        houses.push_back(temp);
    }
    sort(houses.begin(), houses.end());
    int low = 1,
        high = houses[n - 1] - houses[0],
        result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            result = max(result, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << result << endl;
    return 0;
}