// https://www.acmicpc.net/problem/14888
// BACKTRACKING (7), 연산자 끼워넣기
// NUMBER 14888

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 모든 경우의 수를 구해서 값을 구해야하므로 DFS 를 통해 품

// 주어지는 연산자는 정수로 입력받아 배열에 저장하고
// 연산자 배열을 DFS 하여 정렬된 연산자를 이용하여 값을 계산함

#include <iostream>
#include <vector>
using namespace std;

#define MAX 11

bool visited[MAX - 1];
int n, nArr[MAX], oArr[MAX - 1];
int maxValue = -1000000000, minValue = 1000000000;
vector<int> operVec;

int Calculate()
{
    int temp;
    switch (operVec[0])
    {
    case 0:
        temp = nArr[0] + nArr[1];
        break;
    case 1:
        temp = nArr[0] - nArr[1];
        break;
    case 2:
        temp = nArr[0] * nArr[1];
        break;
    case 3:
        temp = nArr[0] / nArr[1];
        break;

    default:
        break;
    }

    for (int i = 2; i < n; i++)
    {
        switch (operVec[i - 1])
        {
        case 0:
            temp += nArr[i];
            break;
        case 1:
            temp -= nArr[i];
            break;
        case 2:
            temp *= nArr[i];
            break;
        case 3:
            temp /= nArr[i];
            break;

        default:
            break;
        }
    }
    return temp;
}

void Dfs(int cnt)
{
    if (cnt == n - 1)
    {
        int result = Calculate();
        if (maxValue < result)
            maxValue = result;
        if (minValue > result)
            minValue = result;
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        operVec.push_back(oArr[i]);
        Dfs(cnt + 1);
        visited[i] = false;
        operVec.pop_back();
    }
}

void input()
{
    int temp, cTemp = 0;
    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 0;
        cTemp++;
    }

    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 1;
        cTemp++;
    }

    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 2;
        cTemp++;
    }

    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 3;
        cTemp++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nArr[i];
    }

    input();
    Dfs(0);

    cout << maxValue << endl
         << minValue << endl;

    return 0;
}
