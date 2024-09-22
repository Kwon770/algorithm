// https://www.acmicpc.net/problem/1037
// math3 (2) 약수
// NUMBER 1037

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// 진짜 약수가 주어진다면 무조건 제일 작은수 x 제일 큰수 = 원본 수
// 9와 같이 진짜 약수가 1 개일 경우, 인덱스를 통해 해결

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int count, temp;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cout << v[0] * v[count - 1] << endl;

    return 0;
}