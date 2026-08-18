// NAO TESTADO E CONHECIMENTO 0 
struct BIT {
    int n;
    vi tree;

    BIT(int n) : n(n) {
        tree.assign(n + 1, 0);
    }

    void add(int i, int val) {
        for (; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
