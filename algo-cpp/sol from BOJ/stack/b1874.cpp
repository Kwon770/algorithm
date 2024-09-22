// https://www.acmicpc.net/problem/1874
// Stack(5), 스택 수열
// NUMBER 1874

// 주어진 수열을 스택을 이용하여 구현할 수 있는지 확인하고, 구현할 수 있다면 push, pop 순서까지 출력해야 함.
// 이 순서까지 구현하는 것은 어떤 규칙을 파악해서 계산하는 것이 힘들고, 입력이 오름찬순이며, 직접 시현해보는 것이 많은 반복이 필요한 것이 아니므로,
// 직접 스택을 통해 시현하는 것으로 구현.

#include <iostream>
#include <stack>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string cmd = "";
    stack<int> stack;
    int input[100000];
    int n, o = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 1; i <= n; i++)
    {
        stack.push(i);
        cmd += "+\n";
        while (!stack.empty() && stack.top() == input[o])
        {
            stack.pop();
            cmd += "-\n";
            o++;
        }
    }
    if (stack.empty())
        cout << cmd << endl;
    else
        cout << "NO" << endl;
    return 0;
}