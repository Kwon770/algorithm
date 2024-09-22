// https://www.acmicpc.net/problem/1259
// NUMBER 1259 팰린드롬수

#include <iostream>
using namespace std;
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        string input;
        cin >> input;
        if (input == "0")
            break;

        bool no = false;
        int idx = input.size() - 1;
        for (int i = 0; i < idx; i++)
        {
            if (input[i] != input[idx])
            {
                no = true;
                break;
            }
            idx--;
        }
        if (no)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}