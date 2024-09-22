// https://www.acmicpc.net/problem/10816
// Binaray Search(2), 숫자 카드 2
// NUMBER 10816

// Binaray Search, https://www.notion.so/sckwon770/Binaray-Search-b50720f0f2df4aa486cf6b3b4797b6d2

// 이분 탐색을 통해 target 을 찾은 후 앞뒤로 몇개가 있는지를 세리는 코드를 짰으나, 시간 초과가 발생함.
// target 이 많을수록 많은 연산이 필요하므로, lower_bound 를 이용하여 2번의 이분 탐색으로 답을 구할 수 있음.

// lower_bound(container.begin(), container.end(), target) - container => target의 인덱스
// lower_bound(mtemp): mtemp 를 이분 탐색으로 찾음
// lower_bound(mtemp + 1): mtemp + 1, 즉 mtemp 바로 다음으로 큰 수를 이분 탐색으로 찾음.
// (mtemp + 1 이 없는 경우, 그 보다 큰 수중에서 가장 작은 수를 찾음)
// 이 둘의 차를 통해 인덱스의 차를 구하게 되므로, 몇 개인지를 구할 수 있음.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, mtemp;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input.begin(), input.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> mtemp;
        auto low = lower_bound(input.begin(), input.end(), mtemp);
        auto high = lower_bound(input.begin(), input.end(), mtemp + 1);
        cout << high - low << " ";
    }
    return 0;
}