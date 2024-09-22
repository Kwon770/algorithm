// https://www.acmicpc.net/problem/2805
// Binaray Search(4), 나무 자르기
// NUMBER 2805

// Binaray Search, https://www.notion.so/sckwon770/Binaray-Search-b50720f0f2df4aa486cf6b3b4797b6d2

// 각 나무으 최대 길이 10억, 요구하는 나무 길이 최대 20억 이므로,
// 계산 과정에서 오버플로우 발생을 방지하기 위해 long long 사용

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> wood(n);
    for (int i = 0; i < n; i++)
        cin >> wood[i];

    long long left = 1,
              right = *max_element(wood.begin(), wood.end()),
              maxCut = 0;
    while (left <= right) {
        long long mid = (left + right) / 2,
                  obtainedWood = 0;
        for (int i = 0; i < n; i++)
            if (wood[i] > mid)
                obtainedWood += wood[i] - mid;

        if (obtainedWood > m) {
            left = mid + 1;
            maxCut = max(maxCut, mid);
        } else if (obtainedWood < m)
            right = mid - 1;
        else {
            maxCut = max(maxCut, mid);
            break;
        }
    }

    cout << maxCut << endl;
    return 0;
}