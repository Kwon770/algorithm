// https://www.acmicpc.net/problem/4949
// Stack(4), 균형잡힌 세상
// NUMBER 4949

// 괄호 종류에 따라 짝이 맞음으로써 균형이 잡혔는지 안잡혔는지를 확인한다.
// 문제의 접근은 이전 문제인 9012번과 같다
// https://github.com/Kwon770/Algorithm/blob/master/boj/Stack_/b9012.cpp

// vector 보다는 empty() top() 모두 지원하는 stack 이 코드를 더 효율족으로 줄여줌
// (vector는 요소 참조하는 과정에서 런타임 오류가 발생할 수 있음)

#include <iostream>
#include <stack>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    bool isBlanace;
    while (true)
    {
        getline(cin, input);
        if (input == ".")
            break;

        stack<char> stack;
        isBlanace = true;
        for (int i = 0; i < input.length() && isBlanace; i++)
        {
            switch (input[i])
            {
            case '[':
            case '(':
                stack.push(input[i]);
                break;
            case ']':
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                    isBlanace = false;
                break;
            case ')':
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    isBlanace = false;
                break;
            default:
                break;
            }
        }

        if (isBlanace && stack.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}