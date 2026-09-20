#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

struct segtree {
    struct node {
        int cap = 0;
        int free = 0;
        int lazy = -1;
    };
    int n;
    vector<node> t;
    segtree(const vi &a) {
        n = a.size();
        t.resize(4*n);
        build(1, 0, n, a);
    }
    node merge(node a, node b){
        return {a.cap+b.cap, a.free+b.free};
    }
    void build(int p, int l, int r, const vi &a) {
        if (r - l == 1) {
            t[p].cap = a[l];
            t[p].free = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m, r, a);
        pull(p);
    }
    void pull(int p) {
        t[p].cap = t[p << 1].cap + t[p << 1 | 1].cap;
        t[p].free = t[p << 1].free + t[p << 1 | 1].free;
    }
    void apply(int p, int v) {
        t[p].free = v ? t[p].cap : 0;
        t[p].lazy = v;
    }
    void push(int p) {
        if (t[p].lazy == -1) return;
        apply(p << 1, t[p].lazy);
        apply(p << 1 | 1, t[p].lazy);
        t[p].lazy = -1;
    }
    node query(int p, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return {0,0};
        if (ql <= l && r <= qr) return t[p];
        push(p);
        int m = (l + r) >> 1;
        return merge(query(p << 1, l, m, ql, qr),
                    query(p << 1 | 1, m, r, ql, qr));
    }
    node query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    void upd(int p, int l, int r, int ql, int qr, int v) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            apply(p, v); return;
        }
        push(p);
        int m = (l + r) >> 1;
        upd(p << 1, l, m, ql, qr, v);
        upd(p << 1 | 1, m, r, ql, qr, v);
        pull(p);
    }
    void upd(int l, int r, int v) {
        if (l >= r) return;
        upd(1, 0, n, l, r, v);
    }
    int findFirst(int p, int l, int r, int &x) {
        if (r - l == 1) return l;
        push(p);
        int m = (l + r) >> 1;
        if (t[p << 1].free > x) return findFirst(p << 1, l, m, x);

        x -= t[p << 1].free;
        return findFirst(p << 1 | 1, m, r, x);
    }
    int findFirst(int x) {
        return findFirst(1, 0, n, x);
    }
    void add(int p, int l, int r, int pos, int x) {
        if (r - l == 1) {
            t[p].free -= x;
            t[p].lazy = -1;
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        if (pos < m) add(p << 1, l, m, pos, x);
        else add(p << 1 | 1, m, r, pos, x);

        pull(p);
    }
    void add(int pos, int x) {
        add(1, 0, n, pos, x);
    }
    void pour(int b, int v) {
        int total = query(0, b + 1).free;
        if (total <= v) {
            upd(0, b + 1, 0);
            return;
        }
        int target = total - v;
        int j = findFirst(target);

        int prefix = query(0, j + 1).free;
        upd(j + 1, b + 1, 0);
        add(j, prefix - target);

        upd(j+1, b+1, 0);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    for (int &x : a) cin >> x;
    segtree seg(a);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int b, v; cin >> b >> v;
            b--;
            seg.pour(b, v);
        } else {
            int l, r; cin >> l >> r;
            l--;
            auto res = seg.query(l, r);
            cout << res.cap - res.free << '\n';
            seg.upd(l, r, 1);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;
}

