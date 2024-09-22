// https://www.acmicpc.net/problem/14889
// BACKTRACKING (8), 스타트와 링크
// NUMBER 14889

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 1 ~ N 번의 사람들의 두 팀으로 나눈 후, 2차원 배열로 주어진 능력치를 모두 더하여 나눈 경우의 수마다의 팀간 격차 최소값을 구하여 풀이
// 1 ~ N 연속된 숫자의 사람들을 두 팀으로 나누고 모든 경우의 수를 확인해야 하므로, DFS 를 통해 모든 경우를 조사

// 두 팀의 선수들은 순서에 상관없고 Dfs와 관련된 입출이 편한 vector 에 저장함

// Dfs 를 통해 start 팀을 구성하고, start 팀 외의 사람들은 link 팀으로 간주하여 계산
// link팀은 반복문을 통해 std::find 를 통해 start 팀의 벡터를 탐색하여 구함

// ==> 다만 쓸데없는 연산으로 시간 초과 ==> b14889-studt.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define endl "\n"
#define MAX 20

int arr[MAX][MAX], N;
bool selected[MAX];
vector<int> startVec;
vector<int> linkVec;

int minResult = INT32_MAX;

int Calculate()
{
    for (int i = 0; i < N; i++)
    {
        if (find(startVec.begin(), startVec.end(), i) != startVec.end())
            continue;

        linkVec.push_back(i);
    }

    int startValue = 0, linkValue = 0;
    for (int i = 0; i < N / 2; i++)
    {
        for (int o = 0; o < N / 2; o++)
        {
            if (i == o)
                continue;

            startValue += arr[startVec[i]][startVec[o]];
            linkValue += arr[linkVec[i]][linkVec[o]];
        }
    }

    linkVec.clear();
    return abs(startValue - linkValue);
}

void Solve(int cnt)
{
    if (cnt == N / 2)
    {
        minResult = min(minResult, Calculate());
    }

    for (int i = 0; i < N; i++)
    {
        if (selected[i])
            continue;

        selected[i] = true;
        startVec.push_back(i);
        Solve(cnt + 1);
        selected[i] = false;
        startVec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int o = 0; o < N; o++)
        {
            cin >> arr[i][o];
        }
    }

    Solve(0);
    cout << minResult << endl;

    return 0;
}
