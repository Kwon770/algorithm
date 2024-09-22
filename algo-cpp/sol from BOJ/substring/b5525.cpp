// https://www.acmicpc.net/problem/1504
// Shortest path (2), 특정한 최단 경로
// NUMBER 1504

// 직관적으로 문자열을 순회하며, 일하는 문자로 시작할 경우, 다시 반복문을 통해 확인하는 코드는 O(N^2) 이다.
// 따라서, O(N^2) 까지 줄여야 TLE가 발생하지 않는다.

// 시간복잡도를 줄이기 위한 핵심은 O의 개수를 통해서 문자열의 일치여부를 확인하는 것이다.
// (1) 번 코드
// 물론 "OO"와 같이 연속으로 O가 붙어있는 예외는 한번에 두 자리의 문자열을 확인함으로써, 예외를 방지한다.

// (2) 번 코드
// 또한 이 문제는 문자열이 일부 겹쳐 있어도 괜찮으므로, 이 또한 문자열울 확인하는 과정에서 고려해야 한다.
// 반복문을 break 하지 않고, oCnt 하나만 줄여서 그 다음 문자열 2자리도 조건을 만족하면, 바로 oCnt가 충족하게 되어서
// 일부분이 겹치는 문자열 일치도 확인할 수 있다.
// standard = IOIO // input = IOIOIO // 'IOIO'IO => oCnt - 1 => IO'IO'IO => next step => IO'IOIO'

#include <iostream>
#define endl "\n"
#define INF 987654321
#define MAX_V 801
#define MAX_E 200001
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt = 0;
    string input;
    cin >> n >> m >> input;

    // 시간 복잡도는 O(N)
    for (int i = 0; i < m; i++) {
        // 'O' 의 갯수를 통해 문자열의 일치여부를 확인한다.
        int oCnt = 0;
        while (input[i] == 'I' && input[i + 1] == 'O') {  // (1) 번, 두 자리씩 코드를 확인한다.
            i += 2;
            oCnt++;
            if (input[i] == 'I' && oCnt == n) {
                // (2) 번, 이 논리의 핵심
                // oCnt의 갯수를 빼는 이유는 break문이 없는 것을 보면 알 수 있다.
                // 반복문을 지속하며 계속 문자열 단위별로 갯수를 세아린다.
                oCnt--;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}