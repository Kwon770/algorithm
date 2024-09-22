// https://www.acmicpc.net/problem/7579
// Dynamic Programming2 (5), 앱
// NUMBER 7579

// 이문제는 12865, 배낭문제 (냅색 문제) 와 흡사하지만, 접근을 약간 다르게 해야한다.
// 배낭 문제 솔루션, https://www.notion.so/sckwon770/12865-1b447fa265ce4dc89dabd8e9a79f8000

// 이 문제에서 제시한 변수의 범위(메모리의 범위)가 10,000,000 이다. 이를 배낭문제처럼 한 배열에서
// 관리할 경우, 4gb가 넘어가게 되기 때문에, 약간 다르게 풀어야 한다.

// 배낭문제처럼 인덱스와 구해야 하는 값(앱의 메모리 = 물건의 가치)을 기준으로 하는게 아니라
// 인덱스와 항목 선택을 판가름하는 가치(앱의 비활성화 코스트 = 물건의 무게) 를 기준으로 한다.
// 기준을 바꾸는 이유는 단순히 '앱의 비활성화 코스트'가 범위가 작기때문이다. 기준을 바꿈에 따른 접근방법도 바꿔야 한다.

// 최소의 비활성화 코스트로 충분한 메모리를 얻어야 하므로, 최소의 코스트부터 조금씩 상승하면서 현재 코스트로
// 충분한 메모리를 얻을 수 있는지를 확인하면 된다.

#include <cstring>
#include <iostream>
#define endl "\n"
using namespace std;

const int MAX = 100 + 1;
const int MAXCOST = 10000 + 1;

int task[MAX][MAXCOST];  // index, cost
int memory[MAX], cost[MAX];
int n, m;

int maxMemory(int idx, int totalCost) {
    if (idx > n) return 0;

    int &result = task[idx][totalCost];
    if (result != -1) return result;

    // 현재 idx의 앱을 비활상화 하지 않을 경우
    result = maxMemory(idx + 1, totalCost);

    // totalCost 보다 현재 idx의 앱의 비활성화 코스트가 같거나 작다면
    // 비활성화 안 했을 때(result)와 했을 때를 비교해서 메모리가 더 큰 쪽을 선택
    if (cost[idx] <= totalCost) result = max(result, memory[idx] + maxMemory(idx + 1, totalCost - cost[idx]));
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> memory[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];
    memset(task, -1, sizeof(task));

    for (int i = 0; i <= MAXCOST; i++) {
        if (maxMemory(0, i) >= m) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}