// https://www.acmicpc.net/problem/11866
// Queue_Deque_(3), 요세푸스 문제 0
// NUMBER 11866

// Queue/Dequq 를 이용하여 주어진 문제의 흐름대로 조작하는 문제
// erase 할때마다 인덱스가 한 칸씩 앞으로 당겨지므로 k 만큼 인덱스를 옮길때 조심하여야 함
// erase 할때마다 최대 인덱스가 변하므로, 인덱스를 증가 시킬때 주의하여야 함
// => 단지 curIdx - queueSize 만큼 할 경우, 뺸 후에도 최대 인덱스보다 큰 경우가 있을 수 있음
// deque 에 들어있는 숫자는 1부터 시작이지만, deque 의 시작인덱스는 0임

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
    int n, k;
    cin >> n >> k;
    k--;
    int idx = k;
    for (int i = 1; i <= n; i++)
        deque.push_back(i);
    cout << "<";
    while (deque.size() != 1)
    {
        cout << deque[idx] << ", ";
        deque.erase(deque.begin() + idx);
        n--;
        idx += k;
        if (idx >= n)
            idx %= n;
    }
    cout << deque[0] << ">" << endl;
    return 0;
}