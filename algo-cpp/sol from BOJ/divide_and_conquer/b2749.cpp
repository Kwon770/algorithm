// https://www.acmicpc.net/problem/2749
// Divide_and_conquer(8), 피보나치 수3
// NUMBER 2749

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c

// 직접 계산해서는 시간초과가 발생하므로, 피사노 주기(Pisano Period) 이용함.
// 피보나치 수를 K로 나눈 나머지는 항상 주기를 가지는데 이를 피사노 주기라 함.
// 주기의 길이가 P이면 , N번째 피보나치 수를 M으로 나눈 나머지는 N % P번째 피보나치 수를 M으로 나눈 나머지와 같다.
// M = 10^k 일 때, K > 2라면, 주기는 항상 15 * 10^(k-1)이다.
// 예를 들어, M = 10^6 이라면, 주기는 15 * 10^5 = 1500000

// 피보나치 풀이법 https://www.notion.so/sckwon770/e9d775d099bb4ecf88a9a98f0af0ad94

#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
#define MOD 1000000
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p = 1500000, fibo[1500000];
    fibo[0] = 0;
    fibo[1] = fibo[2] = 1;
    long long n;
    cin >> n;
    n %= p;
    for (int i = 3; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MOD;
    }
    cout << fibo[n] << endl;
    return 0;
}