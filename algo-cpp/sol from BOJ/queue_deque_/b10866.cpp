// https://www.acmicpc.net/problem/10866
// Queue_Deque_(5), 덱
// NUMBER 10866

#include <iostream>
using namespace std;
#define endl '\n'

class Deque
{
    int frontIdx;
    int backIdx;
    int size;
    int dequeSize;
    int *arr;

public:
    Deque()
    {
        frontIdx = 0;
        backIdx = -1;
        size = 0;
        dequeSize = 10;
        arr = new int[10];
    }
    ~Deque()
    {
        delete arr;
    }

    void Check_Size()
    {
        if (dequeSize == backIdx + 1)
        {
            dequeSize *= 2;
            int *temp = new int[dequeSize];
            copy(arr, arr + (dequeSize / 2), temp);
            delete arr;
            arr = temp;
        }
    }
    void Push_Front(int n)
    {
        Check_Size();
        if (size > 0)
        {
            for (int i = backIdx; i >= frontIdx; i--)
                arr[i + 1] = arr[i];
        }
        arr[frontIdx] = n;
        size++;
        backIdx++;
    }
    void Push_Back(int n)
    {
        Check_Size();
        arr[backIdx + 1] = n;
        size++;
        backIdx++;
    }
    void Pop_Front()
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
    void Pop_Back()
    {
        if (size == 0)
            cout << -1 << endl;
        else
        {
            cout << arr[backIdx] << endl;
            backIdx--;
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
            cout << arr[backIdx] << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Deque deque = Deque();
    int n;
    cin >> n;
    string cmd;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            int temp;
            cin >> temp;
            deque.Push_Front(temp);
        }
        else if (cmd == "push_back")
        {
            int temp;
            cin >> temp;
            deque.Push_Back(temp);
        }
        else if (cmd == "pop_front")
            deque.Pop_Front();
        else if (cmd == "pop_back")
            deque.Pop_Back();
        else if (cmd == "size")
            deque.Size();
        else if (cmd == "empty")
            deque.Empty();
        else if (cmd == "front")
            deque.Front();
        else if (cmd == "back")
            deque.Back();
    }
    return 0;
}