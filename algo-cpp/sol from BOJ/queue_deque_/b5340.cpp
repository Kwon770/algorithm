// https://www.acmicpc.net/problem/5340
// Queue_Deque_(7), AC
// NUMBER 5340

// 노션 풀이, https://www.notion.so/sckwon770/5340-AC-a2fdc5f316a44c46b74bd761c7ba35e8

#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;
#define endl '\n'

void split(deque<string> &deq, string str, char deli)
{
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, deli))
    {
        deq.push_back(temp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<string> deq;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        deq.clear();
        string cmd, arr;
        int cnt;
        cin >> cmd >> cnt >> arr;
        arr.erase(0, 1);
        arr.erase(arr.length() - 1, 1);
        split(deq, arr, ',');
        bool isReverse = false, isError = false;
        for (int o = 0; o < cmd.length(); o++)
        {
            if (cmd[o] == 'R')
            {
                isReverse = !isReverse;
            }
            else
            {
                if (deq.empty())
                {
                    cout << "error" << endl;
                    isError = true;
                    break;
                }
                if (isReverse)
                    deq.pop_back();
                else
                    deq.pop_front();
            }
        }
        if (isError)
            continue;

        cout << "[";
        if (isReverse)
        {
            while (!deq.empty())
            {
                cout << deq.back();
                deq.pop_back();
                if (!deq.empty())
                    cout << ",";
            }
        }
        else
        {
            while (!deq.empty())
            {
                cout << deq.front();
                deq.pop_front();
                if (!deq.empty())
                    cout << ",";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}