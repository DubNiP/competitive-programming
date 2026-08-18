//NAO TESTADO E CONHECIMENTO 0
struct LazySegTree {
    int n;
    vi tree, lazy;

    LazySegTree(int n) : n(n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);

            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);

        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        push(node, start, end);

        if (start > end || start > r || end < l) return 0;

        if (start >= l && end <= r) return tree[node];

      
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);

        return p1 + p2;
    }
    void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
