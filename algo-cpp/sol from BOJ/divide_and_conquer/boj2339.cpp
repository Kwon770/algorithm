// https://www.acmicpc.net/problem/2339
// 2339 석판 자르기

// 골1이지만 아이디어를 깨달으면 큰 어려움없이 해결할 수 있는 문제
// 1. "석판을 자를 때에는 이전에 자른 방향과 같은 방향으로는 자를 수 없다" 라는 조건의 구현
// 이 부분은 문제의 말을 이해하기도 어렵고 이걸 어떻게 구현가능한지 깨닫는 것도 어렵다.
// 프로그래밍적으로 설명하면 이전 단계에서 자른 방향과 이전 단계의 절단으로 생긴 현재 단계의 돌들을 자를 때는 그 반대여야 한다.
// 구현은 분할 정복으로 풀면된다라는 사실을 깨달으면 쉽다.
// 결국 잘려진 석판을 분할하여 풀 것이기 때문에 분할된 석판을 자르면 자연스럽게 잘릴 때 마다 그에 맞게 잘라진다.
// 이를 배열을 통한 구현의 시각으로만 바라보면 답이 안나온다.

// 2. 병합을 통한 경우의 수는 경우의 수 곱으로 구현가능하다.
// 분할 정복을 풀이로 섲불리 떠올리기 힘든 점이 잘라진 석판들이 모두 조건을 만족해야 경우의 수가 더해지는데
// 분할된 석판들의 조건을 어떻게 확인하고 이를 어떻게 세리냐는 것이다. 이는 단순히 기저사례를 통한 덧셈 병합에 대해서만
// 생각하면 빠질 수 있는 생각이다. 나눠진 석판의 경우의 수를 서로 다른 경우의 수로 보고 이를 곱하면 된다.
// 특히, 조건에 맞지 않는 석판의 경우는 0이므로 곱하게 되면 결과적으로 0이 되므로 문제도 없다.

// 위 2가지가 문제의 핵심이며, 경우의 수가 없으면 -1을 출력해야 되는 것을 잊으면 안된다....
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int n, ans = 0;
vector<vector<int>> rock;

pair<int, bool> checkValue(int fromR, int toR, int fromC, int toC) {
    int value = 0;
    bool clean = true;
    for (int i = fromR; i <= toR; i++) {
        for (int j = fromC; j <= toC; j++) {
            if (rock[i][j] == 1) clean = false;

            if (rock[i][j] == 2) {
                value++;
            };
        }
    }
    return {value, clean};
}

int recursion(int fromR, int toR, int fromC, int toC, bool dir) {
    pair<int, bool> cur = checkValue(fromR, toR, fromC, toC);
    if (cur.F == 1 && cur.S == true)
        return 1;

    int cnt = 0;
    if (dir) {
        for (int i = fromR + 1; i <= toR - 1; i++) {
            bool cutable = true;
            for (int j = fromC; j <= toC; j++) {
                if (rock[i][j] == 2) {
                    cutable = false;
                    break;
                }
            }
            if (!cutable) continue;

            pair<int, bool> top = checkValue(fromR, i - 1, fromC, toC);
            pair<int, bool> bottom = checkValue(i + 1, toR, fromC, toC);

            if (top.F == 0 || bottom.F == 0 || (top.F == 1 && top.S == false) || (bottom.F == 1 && bottom.S == false))
                continue;
            else if (top.F == 1 && bottom.F == 1 && top.S == true && bottom.S == true) {
                cnt++;
                continue;
            } else {
                cnt += recursion(fromR, i - 1, fromC, toC, !dir) * recursion(i + 1, toR, fromC, toC, !dir);
            }
        }
    } else {
        for (int j = fromC + 1; j <= toC - 1; j++) {
            bool cutable = true;
            for (int i = fromR; i <= toR; i++) {
                if (rock[i][j] == 2) {
                    cutable = false;
                    break;
                }
            }
            if (!cutable) continue;

            pair<int, bool> left = checkValue(fromR, toR, fromC, j - 1);
            pair<int, bool> right = checkValue(fromR, toR, j + 1, toC);

            if (left.F == 0 || right.F == 0 || (left.F == 1 && left.S == false) || (right.F == 1 && right.S == false))
                continue;
            else if (left.F == 1 && right.F == 1 && left.S == true && right.S == true) {
                cnt++;
                continue;
            } else {
                cnt += recursion(fromR, toR, fromC, j - 1, !dir) * recursion(fromR, toR, j + 1, toC, !dir);
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    rock.resize(n, vector<int>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> rock[i][j];
        }
    }

    int ans = recursion(0, n - 1, 0, n - 1, true) + recursion(0, n - 1, 0, n - 1, false);
    if (ans == 0)
        cout << -1;
    else
        cout << ans;
    return 0;
}
