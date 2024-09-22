// https://www.acmicpc.net/problem/10773
// Stack(2), 제로
// NUMBER 10773

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec;
    int k, temp, total = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        if (temp == 0)
            vec.pop_back();
        else
            vec.push_back(temp);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        total += vec[i];
    }
    cout << total << endl;
    return 0;
}