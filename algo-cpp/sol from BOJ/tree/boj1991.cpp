#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define ln(x) (int)(x).length()
#define sz(x) (int)(x).size()
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<char> tree(pow(2 * n + 1, n) + 1, -1);
    tree[1] = 'A';
    rep1(i, n) {
        char root, left, right;
        cin >> root >> left >> right;
        if (left == '.' && right == '.') continue;
        int rootIdx = find(tree.begin() + 1, tree.end(), root) - tree.begin();

        if (left != '.')
            tree[rootIdx * 2] = left;
        if (right != '.')
            tree[rootIdx * 2 + 1] = right;
    }
    for (char o : tree) cout << o;
    cout << endl;

    vector<char> order;
    queue<int> q;

    q.push(1);
    while (sz(order) != n) {
        int idx = q.front();
        q.pop();
        order.push_back(tree[idx]);

        if (tree[idx * 2] != -1)
            q.push(idx * 2);
        if (tree[idx * 2 + 1] != -1)
            q.push(idx * 2);
    }
    for (char o : order) cout << o;
    cout << endl;

    return 0;
}
