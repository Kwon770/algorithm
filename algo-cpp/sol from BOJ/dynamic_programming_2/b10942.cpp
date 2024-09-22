#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 2000;

int N, M;
int arr[MAX + 1];
int cache[MAX + 1][MAX + 1];
;

int palindrome(int start, int end) {
    if (start >= end)
        return 1;

    int &result = cache[start][end];
    if (result != -1)
        return result;

    if (arr[start] != arr[end])
        return result = 0;

    return result = palindrome(start + 1, end - 1);
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    cin >> M;
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < M; i++) {
        int S, E;
        scanf("%d %d", &S, &E);
        printf("%d\n", palindrome(S, E));
    }
    return 0;
}