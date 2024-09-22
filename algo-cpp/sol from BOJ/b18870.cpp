// https://www.acmicpc.net/problem/18870
// NUMBER 18870, 좌표 압축

// 딱 보면 브루트포스가 떠오르는 문제이지만, n <= 1,000,000 이므로 최악의 경우 1,000,000^1,000,000
// 단순히 숫자의 크기의 비교라서 숫자의 크기에 해당하는 배열인덱스 생성하기에는, -10^9 <= X <= 10^9

// 따라서 입력받은 수를 정렬하여, 그 인덱스를 통해 해당 숫자보다 작은 숫자의 수를 구하며
// 중복때문에 인덱스가 무의미해지는 것을 막기위해 중복을 모두 제거한다.
// 정렬을 하면 순서대로 출력하기가 어려우므로, 벡터를 두개로 분리하여 진행한다.
// 탐색의 속도 향샹을 위해 이분탐색 lower_bound() 를 쓴다.

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> ipt(n);
    vector<int> iptS(n);
    for (int i = 0; i < n; i++) {
        cin >> ipt[i];
        iptS[i] = ipt[i];
    }
    sort(iptS.begin(), iptS.end());
    iptS.erase(unique(iptS.begin(), iptS.end()), iptS.end());
    for (int i = 0; i < n; i++) {
        cout << lower_bound(iptS.begin(), iptS.end(), ipt[i]) - iptS.begin() << " ";
    }
    cout << endl;
    return 0;
}