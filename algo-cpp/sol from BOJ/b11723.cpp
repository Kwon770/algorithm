// https://www.acmicpc.net/problem/11723
// NUMBER 11723
#include <algorithm>
#include <iostream>
#define endl "\n"
using namespace std;

class Set {
    int* arr;

public:
    Set()
    {
        arr = new int[20];
        fill(arr, arr + 20, 0);
    }
    ~Set() { delete arr; }

    void add(int i)
    {
        if (!arr[i - 1])
            arr[i - 1] = i;
    }

    void remove(int i)
    {
        if (arr[i - 1])
            arr[i - 1] = 0;
    }

    void check(int i)
    {
        if (arr[i - 1])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    void toggle(int i)
    {
        if (arr[i - 1])
            arr[i - 1] = 0;
        else
            arr[i - 1] = i;
    }

    void all()
    {
        delete arr;
        arr = new int[20];
        for (int i = 0; i < 20; i++) {
            arr[i] = i + 1;
        }
    }

    void empty()
    {
        delete arr;
        arr = new int[20];
        fill(arr, arr + 20, 0);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Set set = Set();
    string cmd;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> temp;
            set.add(temp);
        } else if (cmd == "remove") {
            cin >> temp;
            set.remove(temp);
        } else if (cmd == "check") {
            cin >> temp;
            set.check(temp);
        } else if (cmd == "toggle") {
            cin >> temp;
            set.toggle(temp);
        } else if (cmd == "all")
            set.all();
        else if (cmd == "empty")
            set.empty();
    }
    return 0;
}
