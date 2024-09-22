// https://www.acmicpc.net/problem/11653
// math3 (3) 소인수분해
// NUMBER 11653

// Math Theorem, https://www.notion.so/sckwon770/Math-Theorem-6a3043ed872b41b88fbbafaddbde2fc2

// 특정 수로 숫자가 나눠지면 소인수분해가 되었다고 생각할 수 있음

// 2부터 N 까지의 모든 수를 나눠지는지 확인.
// 같은 수로 여러 번 분해되는 경우, 그 순서가 섞이지 않으므로, 한번에 여러번 나누는 것이 효율적.
// 2 ~ N를 매번 소수 확인하지 않고 2 ~ N 의 수가 나눠지는지 확인만 하면 됨
// 낮은 소수가 일찍이 나눠지기 때문에 소수가 아닌 수가 나눠지진 않음.

// 코드 개선
// 낮은 수부터 차례로 나눠 볼 경우, 낮은 수부터 나눠지므로 정렬할 필요가 없음
// 따라서 벡터 사용치 않고 바로 출력.

#include <iostream>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                cout << i << endl;
                n /= i;
            }
        }
    }

    return 0;
}

// bool Desc(int a, int b)
// {
//     return a > b;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     vector<int> v;
//     int n;

//     cin >> n;

//     while (n > 1)
//     {
//         for (int i = 2; i <= n; i++)
//         {
//             while (n % i == 0)
//             {
//                 v.push_back(i);
//                 n /= i;
//             }
//         }
//     }

//     sort(v.begin(), v.end(), Desc);

//     while (!v.empty())
//     {
//         cout << v[v.size() - 1] << endl;
//         v.pop_back();
//     }

//     return 0;
// }