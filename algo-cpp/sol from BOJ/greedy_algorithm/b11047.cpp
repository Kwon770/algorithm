// https://www.acmicpc.net/problem/11047
// Greedy Algorithm(1), 동전 0
// NUMBER 11047

// Greedy Algorithm, https://www.notion.so/sckwon770/Greedy-Algorithm-5f306db9c09945caa986ddc5989e4414

// 동전의 조건이 특별해서 그리디 알고리즘을 사용가능한 문제
// 거스름돈 문제는 수학적으로 빠르게 풀 수 있지만, 그리다 알고리즘 학습이 목적이므로
// 그리디 알고리즘의 흐름을 사용하여 품

// 1. 해 선택 > 2. 적절성 검사 > 3. 해 검사

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, idx, coin[10], cnt = 0, temp = 0;
    cin >> n >> k;
    idx = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    while (temp != k) {
        temp += coin[idx];
        if (temp <= k) {
            cnt++;
        } else {
            temp -= coin[idx];
            idx--;
        }
    }

    cout << cnt << endl;
    return 0;
}