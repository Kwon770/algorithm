// https://www.acmicpc.net/problem/2668
// 2668 숫자고르기
// Memory : 2028 KB , Time : 0 ms
//
// 테케가 규칙을 찾기쉽운 테케이므로, 테케를 따라가다보면 규칙이 보인다.
// 첫째 줄이 중복없이 순서대로인 숫자들이므로, 두 집합이 일치할려면 결국 뽑을 때부터 짝이 맞아야 한다.
// 그렇다는건 표의 숫자를 따라 하나 씩 넣다가 시작한 숫자로 들아온다면 짝이 맞는 숫자들. 짝이 맞지않으면(이미 방문한 숫자에 도달) 짝이 맞지 않는 숫자
// 지금 선택하는 숫자들과 다음 단계에서 선택한 숫자들이 합쳐지면 결국 짝이 맞을 수 있지 않냐는 생각이 들 수 있는데, 첫 째줄이 중복없는 숫자라는 것을
// 생각해보면 그런 반례는 없다.
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int N, ans = 0;
vector<bool> visited;
vector<int> vec, ansVec;

void solve(int start) {
    vector<int> tmp;
    vector<bool> tmpVisited(visited);

    int cur = start;
    while (!tmpVisited[cur]) {
        tmp.push_back(cur);
        tmpVisited[cur] = true;
        cur = vec[cur];

        if (start == cur) {
            for (int t :  tmp) {
                visited[t] = true;
                ansVec.push_back(t);
                ans++;
            }
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vec.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
        if (i == vec[i]) {
            visited[i] = true;
            ansVec.push_back(i);
            ans++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            continue;
        }

        solve(i);
    }

    sort(ansVec.begin(), ansVec.end());
    cout << ans << endl;
    for (auto a : ansVec) {
        cout << a << endl;
    }

    return 0;
}