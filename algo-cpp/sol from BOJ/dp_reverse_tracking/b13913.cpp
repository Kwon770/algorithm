// https://www.acmicpc.net/problem/14003
// DP and Shortest path reverse tracking(6), 13913 숨바꼭질4

// 각 좌표에 fastest time 을 가지고, 현재 확인하는 좌표로 부터의 이동이
// 이미 계산된 fastest time 보다 더 빠른 경우(가치있는 경우, 갱싱해야 하는 경우)
// fastest time을 갱신한다.

// 경로 추적이 필요하므로 별도의 previous 배열을 통해 자취를 추적한다.
// previous 배열을 이용하는 경우 출력할때 뒤집어야 하는데, 이를 해결하기 위해
// next 배열로 바꾸는 것은 불가능하다. 코드의 흐름상 한 좌표에서 다른 여러 좌표로
// 갈 수 있는 경우가 많다. 따라서 여러 좌표의 적절성을 판단하는 과정에서 해당 좌표의 next 배열이
// 계속 갱신되면서 쓰레기값이 들어갈 수 있다.

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

#define endl "\n"
#define MAX 200000
using namespace std;

deque<int> queue;
vector<int> previous(200001);
vector<int> fastestTime(200001);
int n, k;

bool sol(int cur, int prev) {
    if (cur > MAX || cur < 0 || ((fastestTime[cur] != -1) && (fastestTime[cur] < fastestTime[prev] + 1))) {
        return false;
    }

    previous[cur] = prev;
    fastestTime[cur] = fastestTime[prev] + 1;
    if (cur == k) {
        return true;
    }
    queue.push_back(cur);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    fill(fastestTime.begin(), fastestTime.end(), -1);
    fastestTime[n] = 0;
    previous[n] = n;

    queue.push_back(n);
    while (n != k) {
        int idx = queue.front();
        queue.pop_front();

        if (sol(idx * 2, idx)) break;
        if (sol(idx + 1, idx)) break;
        if (sol(idx - 1, idx)) break;
    }

    cout << fastestTime[k] << endl;

    deque<int> output;
    output.push_front(k);
    int idx = k;
    for (int i = 0; i < fastestTime[k]; i++) {
        output.push_front(previous[idx]);
        idx = previous[idx];
    }
    while (!output.empty()) {
        cout << output.front() << " ";
        output.pop_front();
    }

    return 0;
}