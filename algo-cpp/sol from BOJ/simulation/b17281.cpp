// https://www.acmicpc.net/problem/17281
// ⚾

// Brute Force 방식으로 선수들의 순서의 모든 경우의 수를 만들고
// 각 경우의 수의 점수를 simulation하면서 점수를 비교함.
// 모든 경우의 수 (순열 뽑기) + 점수 계산 (simulation) 방식의 풀이.

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int t, maxScore = 0;
int sequence[9] = {2, 3, 4, 1, 5, 6, 7, 8, 9};
vector<vector<int> > scores(50, vector<int>(10, 0));

bool runThrough(int idx, int kind) {
    if (idx + kind > 3)
        return true;
    else
        return false;
}

int compareScore() {
    int score = 0;
    int hitterIdx = -1;

    for (int e = 0; e < t; e++) {
        int out = 0;
        bool base[4];
        fill_n(base, 4, false);

        while (true) {
            hitterIdx = hitterIdx == 8 ? 0 : hitterIdx + 1;

            base[0] = true;
            int kind = scores[e][sequence[hitterIdx]];

            if (kind == 0) {
                out++;
                if (out == 3)
                    break;
            } else if (kind == 4) {
                for (int j = 0; j <= 3; j++) {
                    if (base[j]) {
                        score++;
                        base[j] = false;
                    }
                }
            } else {
                for (int j = 3; j >= 0; j--) {
                    if (base[j]) {
                        if (runThrough(j, kind))
                            score++;
                        else
                            base[j + kind] = true;

                        base[j] = false;
                    }
                }
            }
        }
    }
    return score;
}

void permuationRecursion(int idx) {
    if (idx == 8) {
        maxScore = max(compareScore(), maxScore);
    }

    for (int i = idx; i < 9; i++) {
        if (i == 3) continue;

        swap(sequence[idx], sequence[i]);
        permuationRecursion(idx + 1 == 3 ? 4 : idx + 1);
        swap(sequence[idx], sequence[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> scores[i][j];
        }
    }

    permuationRecursion(0);
    cout << maxScore << endl;
    return 0;
}
