// https://www.acmicpc.net/problem/2261
// Divide_and_conquer(10), 가장 가까운 두 점
// NUMBER 2261

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c
// 분할정복으로 푼 코드, https://casterian.net/archives/92
// 노션 정리, https://www.notion.so/sckwon770/2261-7e5362e6833f4a12bf48529b333b9019

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

struct Point {
    int x, y;
};

int dist(Point &u, Point &v) {
    return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}

bool comp1(const Point &u, const Point &v) {
    return u.x < v.x;
}
bool comp2(const Point &u, const Point &v) {
    return u.y < v.y;
}

int closest_pair(vector<Point>::iterator it, int n) {
    if (n == 2)
        return dist(it[0], it[1]);
    else if (n == 3)
        return min(min(dist(it[0], it[1]), dist(it[1], it[2])), dist(it[2], it[0]));

    int line = (it[n / 2 - 1].x + it[n / 2].x) / 2;
    int d = min(closest_pair(it, n / 2), closest_pair(it + n / 2, n / 2));

    vector<Point> mid;
    for (int i = 0; i < n; i++) {
        int t = line - it[i].x;
        if (t * t < d)
            mid.push_back(it[i]);
    }

    sort(mid.begin(), mid.end(), comp2);

    int mid_sz = mid.size();
    for (int i = 0; i < mid_sz; i++)
        for (int j = i + 1; j < mid_sz && (mid[j].y - mid[i].y) * (mid[j].y - mid[i].y) < d; j++)
            d = min(d, dist(mid[i], mid[j]));

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto it = points.begin(); it != points.end(); it++)
        cin >> it->x >> it->y;
    sort(points.begin(), points.end(), comp1);

    cout << closest_pair(points.begin(), n);
    return 0;
}