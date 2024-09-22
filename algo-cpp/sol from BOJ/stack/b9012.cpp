// https://www.acmicpc.net/problem/9012
// Stack(3), 괄호
// NUMBER 9012

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> vec;
    string input;
    bool isVsc = true;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vec.clear();
        isVsc = true;

        cin >> input;
        for (int o = 0; o < input.length(); o++)
        {
            if (input[o] == '(')
                vec.push_back(input[o]);
            else
            {
                if (vec.size() == 0)
                {
                    isVsc = false;
                    break;
                }

                if (vec[vec.size() - 1] == '(')
                    vec.pop_back();
                else
                {
                    isVsc = false;
                    break;
                }
            }
        }

        if (!isVsc || vec.size() != 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}