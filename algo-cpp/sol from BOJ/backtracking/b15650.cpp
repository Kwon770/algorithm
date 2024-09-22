// https://www.acmicpc.net/problem/15650
// BACKTRACKING (2),
// NUMBER 15650

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 중복을 제외한 모든 조합을 출력해야 하므로 원리를 이용한 재귀 함수를 이용하여 품
// 1 2 3 4 5 -> (1) 2 3 4 5  > 1 (2) 3 4 5 > 1 2 (3) 4 5 >>
//                  - - - -          - - -           - -

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
    cout << endl;
}

void loop(int cnt, int idx)
{
    if (cnt == m)
    {
        PrintAll();
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        v.push_back(i);
        loop(cnt + 1, i + 1);
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