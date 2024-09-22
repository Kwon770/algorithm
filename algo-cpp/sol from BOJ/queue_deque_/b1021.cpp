// https://www.acmicpc.net/problem/1021
// Queue_Deque_(6), 회전하는 큐
// NUMBER 1021

// 규칙에 따라 정해진 연산을 사용하여 시물레이션 하면 됨
// 뽑아낼 원소를 왼쪽을 빼내는 것과 오른쪽으로 뺴내는 것 중 어느 것이 최소연산인지 비교

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> deque;
    int n, m, temp, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        deque.push_back(i);
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        std::deque<int>::iterator it = find(deque.begin(), deque.end(), temp);
        int idx = distance(deque.begin(), it);
        int oppIdx = deque.size() - idx;
        if (idx < oppIdx)
        {
            for (int o = 0; o < idx; o++)
            {
                deque.push_back(deque.front());
                deque.pop_front();
            }
            deque.pop_front();
            cnt += idx;
        }
        else
        {
            for (int o = 0; o < oppIdx - 1; o++)
            {
                deque.push_front(deque.back());
                deque.pop_back();
            }
            deque.pop_back();
            cnt += oppIdx;
        }
    }
    cout << cnt << endl;
    return 0;
}