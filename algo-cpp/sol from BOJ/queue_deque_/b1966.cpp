// https://www.acmicpc.net/problem/1966
// Queue_Deque_(4), 프린터큐
// NUMBER 1966

// 문제에서 주어진 프린트터의 흐름대로 큐를 조작함.
// 중요도를 확인하는 루프설계를 조심해야함 => 출력할 내용이 단순한 계산을 통해 얻는 값이 아니므로
// 루프과정내에서 출력 순서와 m의 인덱스를 계산해줘야됨.
// dequq 초기화 잊지말기

#include <iostream>
#include <deque>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> deque;
    int t, n, m, temp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int cnt = 0;
        deque.clear();
        cin >> n >> m;
        for (int o = 0; o < n; o++)
        {
            cin >> temp;
            deque.push_back(temp);
        }
        while (true)
        {
            bool redo = false;
            for (int o = 1; o < deque.size(); o++)
            {
                if (deque.front() < deque[o])
                {
                    redo = true;
                    break;
                }
            }
            if (redo)
            {
                m--;
                deque.push_back(deque.front());
                deque.pop_front();
                if (m == -1)
                    m = deque.size() - 1;
            }
            else
            {
                cnt++;
                m--;
                deque.pop_front();
                if (m == -1)
                {
                    cout << cnt << endl;
                    break;
                }
            }
        }
    }

    return 0;
}