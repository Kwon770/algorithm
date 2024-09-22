// https://www.acmicpc.net/problem/15652
// BACKTRACKING (4),
// NUMBER 15652

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 중복을 포함하나 수열내에서 오름차순이여 하므로
// 단순 재귀 함수에서 반복문 조건을 변경하여 풀이함.

#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

int n, m;
vector<int> v;

void PrintAll()
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void loop(int cnt, int prev)
{
    if (cnt == m)
    {
        PrintAll();
        return;
    }

    for (int i = prev; i <= n; i++)
    {
        v.push_back(i);
        loop(cnt + 1, i);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    loop(0, 1);
    return 0;
}