// https://www.acmicpc.net/problem/1074
// NUMBER 1074, Z

// 단순하게 #분할정복 #dp #재귀 를 활용한다.
// 번호가 붙기시작하는 최소단위 1칸의 직사각형이 될때까지, 재귀를 통한 분할정복을 하고 번호를 붙이기 시작한다.

// 단, 번호값을들을 배열에 저장하여 번호를 모두 붙이고 나서 정답을 출력해서는 안된다.
// (배열이 관련된 문재를 볼때마다 배열을 생성하여 값을 관리하려는 습관 자제하기)
// 1 <= N <= 15 인데, 2차원 배열의 크기는 2^N * 2^N 이므로, 2^15*2^15*4 = 4GB 초과 (런타임 에러)
// 따라서 배열로 번호를 매기지말고, 정답의 좌표가 나올때까지 번호를 카운팅하다가 바로 정답을 출력한다.

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define endl "\n"
using namespace std;

const int dx[] = {0, 1, 0, 1};
const int dy[] = {0, 0, 1, 1};
int cnt = 0, r, c;

void solve(int unit, int fx, int fy) {
    if (unit == 1) {
        for (int i = 0; i < 4; i++) {
            int cx = fx + dx[i];
            int cy = fy + dy[i];

            if (cx == c && cy == r) {
                cout << cnt << endl;
                return;
            }

            cnt++;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int cx = fx + dx[i] * unit;
            int cy = fy + dy[i] * unit;
            solve(unit / 2, cx, cy);
        }
    }
}

int main() {
    int n;
    cin >> n >> r >> c;
    solve(pow(2, n) / 2, 0, 0);
    return 0;
}