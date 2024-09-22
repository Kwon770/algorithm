// https://www.acmicpc.net/problem/12865
// Dynamic Programming (16), 평범한 배낭
// NUMBER 12865

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c
// 12865 Note, https://www.notion.so/sckwon770/12865-1b447fa265ce4dc89dabd8e9a79f8000

#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int bag[101][100001];
vector<pair<int, int> > item;

void solve(int N, int K) {
    for (int i = 0; i < N; i++)
        for (int o = 0; o <= K; o++)
            bag[i][o] = 0;

    for (int i = 0; i < N; i++) {
        for (int o = 0; o <= K; o++) {
            if (i == 0) {
                if (item[i].first <= o) {
                    bag[i][o] = item[i].second;
                }
                continue;
            }
            if (item[i].first <= o)
                bag[i][o] = max(bag[i - 1][o], item[i].second + bag[i - 1][o - item[i].first]);
            else
                bag[i][o] = bag[i - 1][o];
        }
    }
    cout << bag[N - 1][K] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, w, v;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        item.push_back(make_pair(w, v));
    }

    solve(N, K);
    return 0;
}