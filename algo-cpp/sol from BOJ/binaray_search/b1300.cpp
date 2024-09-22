// https://www.acmicpc.net/problem/1300
// Binaray Search(6), K번째 수
// NUMBER 1300

// Binaray Search, https://www.notion.so/sckwon770/Binaray-Search-b50720f0f2df4aa486cf6b3b4797b6d2
// Notion, https://www.notion.so/sckwon770/1300-K-f25f0d49539a4e1da91041612ea1e746

#include <algorithm>
#include <iostream>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    int left = 1, right = k, ans;
    while (left <= right) {
        long long cnt = 0;
        int mid = (left + right) / 2;
        for (int i = 1; i <= n; i++)
            cnt += min(mid / i, n);
        if (cnt < k)
            left = mid + 1;
        else {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}