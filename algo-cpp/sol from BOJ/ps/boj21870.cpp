// https://www.acmicpc.net/problem/21870 시철이가 사랑한 GCD
// Memory : 6496 kb
// Time : 136 ms

// 아름다움 측정 2번의 왼쪽을 선택하거나 오른쪽을 선택한다.
// 5번의 아름다움은 GCD 합의 최댓값을 한다. 이부분들이 문제의 핵심이다.
// 왼쪽을 선택과 오른쪽의 선택이 결과적으로 측정 방법 끝에나온 아름다움이 최대값이여야한다.
// 하지만 어느쪽을 선택해야하는지는 알 수가없다. 더 많은 갯수의 숫자 부분, 혹은 숫자의 합이 큰 부분
// 모두 (5 4 3 2 1) 로 반례가 가능하므로, 모든 경우의 수를 확인해봐야하고, 이 풀이에서는
// 재귀를 이용한 완탐을 이용했다.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n, maxPretty = 0;
vector<int> rooms;

int getGcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int getVectorGcd(vector<int> vec) {
    if (vec.size() == 1) {
        return vec.front();
    }

    int gcd = vec.front();
    for (int ele : vec) {
        gcd = getGcd(gcd, ele);
    }
    return gcd;
}

void recursiveSolve(vector<int> newRooms, int pretty) {
    if (newRooms.size() <= 1) {
        pretty += newRooms.front();
        maxPretty = max(maxPretty, pretty);
        return;
    }

    vector<int> leftRooms;
    for (int i = 0; i < newRooms.size() / 2; i++) {
        leftRooms.push_back(newRooms[i]);
    }
    int leftGcd = getVectorGcd(leftRooms);

    vector<int> rightRooms;
    for (int i = newRooms.size() / 2; i < newRooms.size(); i++) {
        rightRooms.push_back(newRooms[i]);
    }
    int rightGcd = getVectorGcd(rightRooms);

    recursiveSolve(leftRooms, pretty + rightGcd);
    recursiveSolve(rightRooms, pretty + leftGcd);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    rooms.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    recursiveSolve(rooms, 0);

    cout << maxPretty;
    return 0;
}