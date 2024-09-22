// https://www.acmicpc.net/problem/1697
// DFS-BFS (8), 숨바꼭질
// NUMBER 1697

// DFS BFS, https://www.notion.so/sckwon770/DFS-BFS-6ec22005435048b18669df0f2541538c

// 1차원의 문제이기 때문에 BFS를 사용할 경우의 논리가 쉽게 떠오르지 않았다.
// 1차원의 값들을 트리형식으로 시각화하려하지 말고, 내가 시도해봐야하는 경우를 BFS의 큐에 넣는다고 생각해봐야한다.

// 단순히 수학적논리로 풀기위해서 가능한한 2를 곱하다가 1을 더하거나 뺴는 식의 방식은 테스트 케이스에서 부타
// 틀리게 된다. ( 5 > 10 > 9 > 18 > 17 )

// 따라서 모든 경우를 직접해봐야 한다.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;
#define MAX 100000

int main() {
    int visited[MAX + 1];
    memset(visited, 0, sizeof(visited));
    queue<int> Queue;
    int n, k, seg = 1, ans = 0;

    cin >> n >> k;
    Queue.push(n);

    while (!Queue.empty()) {
        int cnt = 0;
        for (int i = 0; i < seg; i++) {
            int cur = Queue.front();
            Queue.pop();

            if (cur == k) {
                cout << ans << endl;
                return 0;
            }
            visited[cur] = 1;

            if (cur + 1 <= MAX && !visited[cur + 1]) {
                Queue.push(cur + 1);
                cnt++;
            }
            if (cur - 1 >= 0 && !visited[cur - 1]) {
                Queue.push(cur - 1);
                cnt++;
            }
            if (cur * 2 <= MAX && !visited[cur * 2]) {
                Queue.push(cur * 2);
                cnt++;
            }
        }
        seg = cnt;
        ans++;
    }
    cout << ans << endl;
    return 0;
}