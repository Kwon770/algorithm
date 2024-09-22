// https://www.acmicpc.net/problem/2261
// Divide_and_conquer(10), 가장 가까운 두 점
// NUMBER 2261

// Divide and Conquer, https://www.notion.so/sckwon770/Divide-and-conquer-568ac70283ce41b29a01c4e147f4830c
// 라인 스윕, Line Sweep, https://www.acmicpc.net/blog/view/25
// 노션 정리, https://www.notion.so/sckwon770/2261-7e5362e6833f4a12bf48529b333b9019

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define endl "\n"

struct Point {
    int x, y;
    Point() {
    }
    Point(int x, int y) : x(x), y(y) {
    }
    bool operator<(const Point &v) const {
        if (y == v.y) {
            return x < v.x;
        } else {
            return y < v.y;
        }
    }
};

bool cmp(const Point &v, const Point &u) {
    return v.x < u.x;
}

int dist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<Point> a(n);
    for (auto it = a.begin(); it != a.end(); it++)
        cin >> it->x >> it->y;
    sort(a.begin(), a.end(), cmp);

    set<Point> candidate = {a[0], a[1]};
    int ans = dist(a[0], a[1]);
    int start = 0;
    for (int i = 2; i < n; i++) {
        Point now = a[i];
        while (start < i) {
            auto p = a[start];
            int x = now.x - p.x;
            if (x * x > ans) {
                candidate.erase(p);
                start++;
            } else {
                break;
            }
        }
        int d = (int)sqrt((double)ans) + 1;
        auto lower_point = Point(-100000, now.y - d);
        auto upper_point = Point(100000, now.y + d);
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);
        for (auto it = lower; it != upper; it++) {
            int d = dist(now, *it);
            if (d < ans) {
                ans = d;
            }
        }
        candidate.insert(now);
    }
    cout << ans << endl;
    return 0;
}