// https://www.acmicpc.net/problem/11401
// Divide_and_conquer(5), 이항 계수 3
// NUMBER 11401

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c
// 자세한 설명은 https://www.notion.so/sckwon770/11401-d70cb5ed9926472e9c6aceb6cffbfade
// VLA 사용으로 인해 물제가 발생함. 자세한 내용은 https://www.notion.so/sckwon770/VLA-4ecf788c19f4462584bee754154aedc8

#include <iostream>
using namespace std;

#define endl "\n"
#define MAX 4000001
#define MOD 1000000007

long long facMod[MAX];

long long power(long long a, long long b) {
    if (b == 1)
        return a;
    else {
        long long temp = power(a, b / 2);
        if (b % 2)
            return ((temp * temp) % MOD * a) % MOD;
        else
            return (temp * temp) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    facMod[0] = 1;
    facMod[1] = 1;
    facMod[2] = 2;
    for (int i = 3; i <= n; i++)
        facMod[i] = (i * facMod[i - 1]) % MOD;
    long long second = (facMod[k] * facMod[n - k]) % MOD;
    cout << (facMod[n] % MOD) * (power(second, MOD - 2) % MOD) % MOD << endl;
    return 0;
}