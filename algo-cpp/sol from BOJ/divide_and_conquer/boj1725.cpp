// https://www.acmicpc.net/problem/1725
// 1725 히스토그램
//
// 알고리즘 스터디의 분할정복 수업을 통해 푼 문제이기 때문에 다양한 풀이 중 분할정복으로 푼 코드이다.
// 히스토그램을 좌우로 분할하고 기저사례 크기가 1 혹은 2인 경우에는 값을 반환한다.
// 반환된 값을 바탕으로 최대 크기를 구하는 병합 과정을 가진다.
// 단, 좌우로 나눌때 생기는 기준점에 걸치는 사각형이 최대 크기인 경우, 좌우의 확인만으로는
// 계산할 수 없으므로 병합할 때, 좌 / 우 / 중간 중 가장 큰 크기를 병합한다.

// 중간에 걸친 최대 크기 사각혀을 구하는 방법은 34줄부터 이어진다.
// 중간 사각형부터 좌우로 확장해나가면서 크기를 확인한다. (단, 좌우 중 크기가 큰 쪽으로 먼저 확장한다.)
//
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

vector<int> square;

int calculate(int from, int to) {
    if (to - from == 0)
        return square[from];
    else if (to - from == 1)
        return max(square[from], square[to]);

    int midIdx = from + ((to - from) / 2);
    int left = calculate(from, midIdx);
    int right = calculate(midIdx + 1, to);
    int mid = square[midIdx], height = square[midIdx], width = 1, mLeftIdx = midIdx - 1, mRightIdx = midIdx + 1;
    while (mLeftIdx >= from && mRightIdx <= to) {
        if (square[mLeftIdx] > square[mRightIdx]) {
            height = min(height, square[mLeftIdx]);
            mLeftIdx--;
        } else {
            height = min(height, square[mRightIdx]);
            mRightIdx++;
        }
        width++;
        mid = max(mid, height * width);
    }

    while (mLeftIdx >= from) {
        height = min(height, square[mLeftIdx]);
        width++;
        mid = max(mid, height * width);
        mLeftIdx--;
    }
    while (mRightIdx <= to) {
        height = min(height, square[mRightIdx]);
        width++;
        mid = max(mid, height * width);
        mRightIdx++;
    }

    return max(mid, max(left, right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    square.resize(n);
    rep(i, n) {
        cin >> square[i];
    }

    cout << calculate(0, n - 1);
    return 0;
}
