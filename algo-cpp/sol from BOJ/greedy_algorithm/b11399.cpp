// https://www.acmicpc.net/problem/11399
// Greedy Algorithm(3), ATM
// NUMBER 11399

// Greedy Algorithm, https://www.notion.so/sckwon770/Greedy-Algorithm-5f306db9c09945caa986ddc5989e4414

// 사람들이 기다린 시간들의 총합의 최소를 구하는 문제이다.
// 결국 뒷 사람들이 기다린 시간은 앞 사람들이 기다린 시간에 영향을 받으므로
// 이들을 최소화할려면 앞 사람들이 기다린 시간을 최소로 하면 된다.

// 적은 수를 앞으로 보내기 위해 오름차순 정렬을 하였고, sort()를 사용함.

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, total = 0;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input + n);
    for (int i = 0; i < n; i++) {
        temp = 0;
        for (int o = 0; o <= i; o++) {
            temp += input[o];
        }
        total += temp;
    }
    cout << total << endl;
    return 0;
}