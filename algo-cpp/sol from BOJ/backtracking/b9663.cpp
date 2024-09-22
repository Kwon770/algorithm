// https://www.acmicpc.net/problem/9663
// BACKTRACKING (5), NQueen
// NUMBER 9663

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 각 퀸의 위치를 추가할때마다 나머지 퀸의 위치가 정해지므로 dfs 방식과 유사함
// 퀸읜 상화좌우 대각선이 이동범위 이므로 문제의 조건을 지키기 위해선 이 위치들을 계산 가능해야힘
// 퀸의 좌우 모든 곳은 불가능한 곳이므로 계산할 가치가 없음 => 한 줄씩 Row 계산
// 대각선은 퀸의 위치와 현재 위치 (row, column) 기울기 = 1 이면 대각선

#include <iostream>
#include <cmath>
using namespace std;

#define endl "\n"

int n, output = 0;
int queenRow[15];

bool isPossible(int c)
{
    for (int i = 1; i < c; i++)
    {
        if (queenRow[i] == queenRow[c])
        {
            return false;
        }
        if (abs(queenRow[i] - queenRow[c]) == abs(i - c))
        {
            return false;
        }
    }
    return true;
}

void dfs(int row)
{
    if (row == n)
    {
        output++;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            queenRow[row + 1] = i;
            if (isPossible(row + 1))
            {
                dfs(row + 1);
            }
            else
            {
                queenRow[row + 1] = 0;
            }
        }
    }
    queenRow[row] = 0;
}

void loop()
{
    for (int i = 1; i <= n; i++)
    {
        for (int o = 0; o < 15; o++)
            queenRow[o] = 0;
        queenRow[1] = i;
        dfs(1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    loop();
    cout << output << endl;
    return 0;
}