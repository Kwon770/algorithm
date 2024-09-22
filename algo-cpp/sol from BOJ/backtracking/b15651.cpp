// https://www.acmicpc.net/problem/15650
// BACKTRACKING (3),
// NUMBER 15650

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 중복을 포함한 모든 조합을 출력하므로 단순 재귀 함수를 사용하여 풀이함.

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

void loop(int cnt)
{
    if (cnt == m)
    {
        PrintAll();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
        loop(cnt + 1);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    loop(0);
    return 0;
}