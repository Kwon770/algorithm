// https://www.acmicpc.net/problem/17219
// NUMBER 17219, 비밀번호 찾기

#include <iostream>
#include <map>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, string> sites;
    int n, m;
    cin >> n >> m;
    string address, password;
    for (int i = 0; i < n; i++) {
        cin >> address >> password;
        sites[address] = password;
    }
    for (int i = 0; i < m; i++) {
        cin >> address;
        cout << sites[address] << endl;
    }
    return 0;
}