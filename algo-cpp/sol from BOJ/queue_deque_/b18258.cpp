// https://www.acmicpc.net/problem/18258
// Queue_Deque_(1), 큐 2
// NUMBER 18258

#include <iostream>
using namespace std;
#define endl '\n'

class Queue
{
    int frontIdx;
    int backIdx;
    int size;
    int queueSize;
    int *arr;

public:
    Queue()
    {
        frontIdx = 0;
        backIdx = 0;
        size = 0;
        queueSize = 10;
        arr = new int[10];
    }
    ~Queue()
    {
        delete arr;
    }

    void Push(int n)
    {
        if (queueSize == backIdx)
        {
            queueSize *= 2;
            int *temp = new int[queueSize];
            copy(arr, arr + (queueSize / 2), temp);
            delete arr;
            arr = temp;
        }
        arr[backIdx] = n;
        size++;
        backIdx++;
    }
    void Pop()
    {
        if (size == 0)
            cout << -1 << endl;
        else
        {
            cout << arr[frontIdx] << endl;
            frontIdx++;
            size--;
        }
    }
    void Size()
    {
        cout << size << endl;
    }
    void Empty()
    {
        if (size == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    void Front()
    {
        if (size == 0)
            cout << -1 << endl;
        else
            cout << arr[frontIdx] << endl;
    }
    void Back()
    {
        if (size == 0)
            cout << -1 << endl;
        else
            cout << arr[backIdx - 1] << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Queue stack = Queue();
    int n;
    cin >> n;
    string cmd;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int temp;
            cin >> temp;
            stack.Push(temp);
        }
        else if (cmd == "pop")
            stack.Pop();
        else if (cmd == "size")
            stack.Size();
        else if (cmd == "empty")
            stack.Empty();
        else if (cmd == "front")
            stack.Front();
        else if (cmd == "back")
            stack.Back();
    }
    return 0;
}