// https://www.acmicpc.net/problem/4256
// 4256 트리
// Memory : 5056 KB , Time : 28 ms
//
// 트리구조와 트리 순회를 이해하고 응용할 수 있어야한다.
// 처음 풀때 전위와 중위의 테케를 분석하며 규칙을 찾고 어영부영 흉내내면서 풀다보니, 결국 반례가 나왔다.
// 흉내내며 구현하는 식으로 풀게되는 문제는 일반적으로 문제와 테케를 해석하면 패턴이 있다.
// 이 문제의 경우
// 1. 전위순회는 차례로 출력되는 순서이므로, 전위순회를 기준으로 트리를 만들어간다.
// 2. 중위순회는 좌우부모순이므로, 중위순회를 이용하면 특정 노드의 왼쪽과 오른쪽 자식의 노드들을 알 수 있다.
// 3. 이 문제는 최대 1000개의 노드가 주어질 수 있으므로, 벡터로 트리를 표현할 경우 편향트리를 고려한 사이즈를 생성해야하므로
// std::length_error 가 발생한다. 따라서 클래스 혹은 구조체로 자식을 연결해야한다.
//
// 그 외에는 노드 find를 위해 vector를 slice(=sublist)하는 복잡도를 줄이기 위해 iterator를 이용하하였다.

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

class Node {
public:
    Node* left = nullptr;
    Node* right = nullptr;
    int num;

    Node() {}

    Node(int n) : num(n) {}
};

int n, preIdx;
vector<int> pre, in;

void solve(vector<int>::iterator beginIt, vector<int>::iterator endIt, Node* parent, bool isLeft) {
    if (beginIt >= endIt) {
        return;
    }

    int curPre = pre[preIdx];
    Node* curNode;
    if (isLeft) {
        curNode = new Node(curPre);
        parent->left = curNode;
    } else {
        curNode = new Node(curPre);
        parent->right = curNode;
    }
    preIdx++;

    auto nodeIt = find(beginIt, endIt, curPre);
    solve(beginIt, nodeIt, curNode, true);
    solve(nodeIt + 1, endIt, curNode, false);
}

void printPostTree(Node* node) {
    if (node->left != nullptr) {
        printPostTree(node->left);
    }

    if (node->right != nullptr) {
        printPostTree(node->right);
    }

    cout << node->num << " ";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        pre.clear();
        pre.resize(n);
        in.clear();
        in.resize(n);
        preIdx = 1;
        for (int j = 0; j < n; j++) {
            cin >> pre[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> in[j];
        }

        Node root = Node(pre.front());
        auto nodeIt = find(in.begin(), in.end(), root.num);
        solve(in.begin(), nodeIt, &root, true);
        solve(nodeIt + 1, in.end(), &root, false);

        printPostTree(&root);
        cout << endl;
    }

    return 0;
}