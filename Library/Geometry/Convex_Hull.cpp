//CODIGO NAO TESTADO E NUNCA USADO 
struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int cross(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<Point> convex_hull(vector<Point>& pts) {
    int n = sz(pts), k = 0;
    if (n <= 2) return pts;
    
    vector<Point> h(2 * n);
    sort(all(pts));

    for (int i = 0; i < n; h[k++] = pts[i++])
        while (k >= 2 && cross(h[k - 2], h[k - 1], pts[i]) <= 0) k--;

    for (int i = n - 2, t = k + 1; i >= 0; h[k++] = pts[i--])
        while (k >= t && cross(h[k - 2], h[k - 1], pts[i]) <= 0) k--;

    h.resize(k - 1);
    return h;
}
