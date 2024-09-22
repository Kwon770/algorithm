// https://www.acmicpc.net/problem/14888
// BACKTRACKING (7), 연산자 끼워넣기
// NUMBER 14888

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 연산자를 배열에 넣고, 배열의 모든 경우의 수를 구하기 위해 DFS 사용하는 것이 아닌,
// DFS 를 통한 재귀 자체의 성질을 이용하여 품

// => 다음과 같이 구조를 바꿈으로써,
// 입력단을 간소화, 퍼포먼스 향상. 식 계산 간소화

// 최댓값 최솟값은 max() min() 함수로 구하기

#include <iostream>
#include <algorithm>
using namespace std;

const int maxValue = 1000000000 + 1;

int N;
int number[12], oper[4];
int maxResult = -maxValue, minResult = maxValue;

void DFS(int plus, int minus, int multiply, int divide, int cnt, int sum)
{
        if (cnt == N)
        {
                maxResult = max(maxResult, sum);
                minResult = min(minResult, sum);
        }

        // DFS 재귀의 성질을 이용한, 탐색
        if (plus > 0)
                DFS(plus - 1, minus, multiply, divide, cnt + 1, sum + number[cnt]);
        if (minus > 0)
                DFS(plus, minus - 1, multiply, divide, cnt + 1, sum - number[cnt]);
        if (multiply > 0)
                DFS(plus, minus, multiply - 1, divide, cnt + 1, sum * number[cnt]);
        if (divide > 0)
                DFS(plus, minus, multiply, divide - 1, cnt + 1, sum / number[cnt]);
}

int main(void)
{
        cin >> N;
        for (int i = 0; i < N; i++)
                cin >> number[i];
        for (int i = 0; i < 4; i++)
                cin >> oper[i];

        DFS(oper[0], oper[1], oper[2], oper[3], 1, number[0]);

        cout << maxResult << endl;
        cout << minResult << endl;
        return 0;
}