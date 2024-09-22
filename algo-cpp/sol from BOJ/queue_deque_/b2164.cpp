// https://www.acmicpc.net/problem/2164
// Queue_Deque_(2), 카드 2
// NUMBER 2164

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        deque.push_front(i);
    while (deque.size() > 1)
    {
        deque.pop_back();
        deque.push_front(deque.back());
        deque.pop_back();
    }
    cout << deque.back() << endl;
    return 0;
}