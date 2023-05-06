#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

struct point {
    int x, y, index;
};


int n, m;
point a[MAXN];
int dist[MAXN];

bool cmp(point A, point B) {
    if (A.x != B.x) return A.x < B.x;
    return A.y < B.y;
}

bool ccw(point A, point B, point C) {
    return (C.y - A.y) * (B.x - A.x) > (B.y - A.y) * (C.x - A.x);
}

vector<point> convex_hull( vector<point> P) {
    int n = P.size(), k = 0;
    vector<point> H(2 * n);
    sort(P.begin(), P.end(), cmp);
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && !ccw(H[k-2], H[k-1], P[i])) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && !ccw(H[k-2], H[k-1], P[i])) k--;
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        dist[i] = INF;
    }
    vector<point> hull = convex_hull(vector<point>(a, a + n));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (ccw(a[u], a[v], hull[0])) {
            dist[u] = min(dist[u], w);
        }
        if (ccw(a[v], a[u], hull[0])) {
            dist[v] = min(dist[v], w);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) continue;
        for (int j = 0; j < hull.size(); j++) {
            if (ccw(a[i], hull[j], hull[(j+1)%hull.size()])) {
                dist[i] = min(dist[i], dist[hull[j].index] + (int)sqrt(pow(a[i].x - hull[j].x, 2) + pow(a[i].y - hull[j].y, 2)));
            }
        }
    }
    cout << dist[n-1] << endl;
    return 0;
}

