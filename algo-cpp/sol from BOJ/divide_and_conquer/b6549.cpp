// https://www.acmicpc.net/problem/6549
// Divide_and_conquer(9), 히스토그램에서 가장 큰 직사각형
// NUMBER 6549

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

void init(vector<int> &arr, vector<int> &tree, int node, int start, int end) {
    // leaf node (what don't have children node)
    if (start == end)
        tree[node] = start;

    // internal node
    else {
        // node * 2 : left children node // node * 2 + 1 : right children node
        int mid = (start + end) / 2;
        init(arr, tree, node * 2, start, mid);
        init(arr, tree, node * 2 + 1, mid + 1, end);

        // 각 구간에서 가장 높이가 낮은 것을 노드에 넣어준다.
        if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2 + 1];
    }
}

// get lowest bar from end to start
int query(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int m1 = query(arr, tree, node * 2, start, mid, left, right);
    int m2 = query(arr, tree, node * 2 + 1, mid + 1, end, left, right);

    if (m1 == -1)
        return m2;

    else if (m2 == -1)
        return m1;

    else {
        if (arr[m1] <= arr[m2])
            return m1;
        else
            return m2;
    }
}

long long getMax(vector<int> &arr, vector<int> &tree, int start, int end) {
    int n = arr.size();
    int m = query(arr, tree, 1, 0, n - 1, start, end);

    long long area = (long long)(end - start + 1) * (long long)arr[m];

    // When there is bar left to lowest bar
    if (start <= m - 1) {
        long long tmp = getMax(arr, tree, start, m - 1);

        if (area < tmp)
            area = tmp;
    }

    // When there is bar right to lowest bar
    if (m + 1 <= end) {
        long long tmp = getMax(arr, tree, m + 1, end);
        if (area < tmp)
            area = tmp;
    }

    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // get segment tree size
        int h = (int)(ceil(log2(n)) + 1e-9);
        int treeSize = (1 << (h + 1));
        vector<int> tree(treeSize);
        init(arr, tree, 1, 0, n - 1);

        cout << getMax(arr, tree, 0, n - 1) << endl;
    }

    return 0;
}