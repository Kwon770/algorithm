// https://www.acmicpc.net/problem/15649
// BACKTRACKING (1),
// NUMBER 15649

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 모든 조합을 출력해야 하므로 DFS 방식을 이용해서 풀이

#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

int n, m;
bool visited[MAX];
vector<int> v;

void PrintAll()
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void Dfs(int cnt)
{
    if (cnt == m)
    {
        PrintAll();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        v.push_back(i);
        Dfs(cnt + 1);
        visited[i] = false;
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    Dfs(0);
    return 0;
}
