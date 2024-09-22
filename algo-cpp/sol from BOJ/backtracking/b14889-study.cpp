// https://www.acmicpc.net/problem/14889
// BACKTRACKING (8), 스타트와 링크
// NUMBER 14889

// Backtracking https://www.notion.so/sckwon770/Backtracking-30cf0d78cc6b4477afac6444df505216

// 선수들을 팀에 나눈 결과르 문자열에 bit (0과 1)을 통해 저장함
// bit string은 매개변수로 전달함으로써, Dfs 마지막 단계에서 요소 제거를 해결할 수 있음
// 조합치 계산 과정애서 각 팀의 반복문을 톤해 계산함 ( 1 : start 팀 0 : link 팀)
// => 각 팀을 관리하던 vector 사용과 std::find 를 통한 vector 탐색을 생략

// Dfs 의 횟수는 bit strig 을 통해 계산

// 일일히 bit string을 확인하며 각 팀의 숫자를 세아리기 힘드므로,
// 각 팀 선수의 수를 매개변수로 전달하고, 이를 이용하여 어느 팀의 선수를 추가할지 결정

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define endl "\n"
#define MAX 20

int arr[MAX][MAX], N, minValue = __INT32_MAX__;
bool selected[MAX];

int Calculate(string bit)
{
    int startValue = 0, linkValue = 0;

    for (int i = 0; i < bit.size(); i++)
    {
        if (bit[i] != '1')
            continue;
        for (int o = 0; o < bit.size(); o++)
        {
            if (bit[o] != '1')
                continue;

            startValue += arr[i][o];
        }
    }

    for (int i = 0; i < bit.size(); i++)
    {
        if (bit[i] != '0')
            continue;
        for (int o = 0; o < bit.size(); o++)
        {
            if (bit[o] != '0')
                continue;

            linkValue += arr[i][o];
        }
    }

    return abs(startValue - linkValue);
}

void Dfs(string bit, int startCnt, int linkCnt)
{
    if (bit.size() == N)
    {
        minValue = min(minValue, Calculate(bit));
    }

    if (startCnt < N / 2)
        Dfs(bit + "1", startCnt + 1, linkCnt);
    if (linkCnt < N / 2)
        Dfs(bit + "0", startCnt, linkCnt + 1);
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

    Dfs("", 0, 0);
    cout << minValue << endl;

    return 0;
}
