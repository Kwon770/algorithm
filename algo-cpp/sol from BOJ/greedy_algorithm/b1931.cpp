// https://www.acmicpc.net/problem/1931
// Greedy Algorithm(2), 화의실배정
// NUMBER 1931

// Greedy Algorithm, https://www.notion.so/sckwon770/Greedy-Algorithm-5f306db9c09945caa986ddc5989e4414

// 주어지는 입력값의 특성상 현재 선택할 수 있는 최대가치의 값을 고르는 방식 그리디 알고리즘을 사용하는 문제
// 얼핏보면 회의 시작시간에 어떤지, 회의 시간이 어떤지를 고려하며 풀어야 해서 브루트포스를 고려하게 되지만
// 문재가 결국 요하는 것은 최대한의 회의의 갯수이며, 이는 회의 종료시간과 관련있다.

// 회의 시작시간이 이전 회의 시간을 침범하지 않고, 회의 종료시간이 최대한 짧으면 최대한의 회의갯구를 구할 수 있다는 원리
// 이를 위해서는 회의 종류시간을 기준으로 정렬된 값들을 순회하며 판단하면 된다.

// 문제의 예시는 종료시간이 이미 정렬되어 있는데, 실제 입력값을 그렇지 않으므로 정렬해야한다
// pair 가 들러간 vector 의 sort() 는 first 인자를 기준으로 정렬하므로, 벡터에 넣을때 반잔하여 넣음

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int> > input, seq;
    int n, t1, t2, idx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        input.push_back(make_pair(t2, t1));
    }

    sort(input.begin(), input.end());
    seq.push_back(input[0]);
    for (int i = 1; i < n; i++) {
        if (seq[idx].first <= input[i].second) {
            seq.push_back(input[i]);
            idx++;
        }
    }

    cout << seq.size() << endl;
    return 0;
}