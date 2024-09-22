// https://www.acmicpc.net/problem/10828
// Stack(1), 스택
// NUMBER 10828

#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

class Stack
{
    int curSize;
    int size;
    int *arr;

public:
    Stack()
    {
        curSize = 0;
        size = 10;
        arr = new int[10];
    }
    ~Stack()
    {
        delete arr;
    }

    void Push(int n)
    {
        if (size == curSize)
        {
            size *= 2;
            int *temp = new int[size];
            copy(arr, arr + (size / 2), temp);
            delete arr;
            arr = temp;
        }
        arr[curSize] = n;
        curSize++;
    }
    void Pop()
    {
        if (curSize == 0)
            cout << -1 << endl;
        else
        {
            cout << arr[curSize - 1] << endl;
            curSize--;
        }
    }
    void Size()
    {
        cout << curSize << endl;
    }
    void Empty()
    {
        if (curSize == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    void Top()
    {
        if (curSize == 0)
            cout << -1 << endl;
        else
            cout << arr[curSize - 1] << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Stack stack = Stack();
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
        else if (cmd == "top")
            stack.Top();
    }

    return 0;
}