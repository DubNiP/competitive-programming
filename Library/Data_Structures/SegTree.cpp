struct SegTree {

    struct Node {
        //Caso queira mudar, mude a info aqui.
        int sum = 0;
        
        static Node combine(const Node& a, const Node& b) {
            return {a.sum + b.sum};
        }
        
        void apply(int v) {
            sum = v;
        }
    };

    int n;
    vector<Node> tree;

 
    SegTree(int size) {
        n = size;
        tree.assign(2 * n, Node());
    }

    void build(const vi& a) {
        for (int i = 0; i < n; i++) {
            tree[n + i].apply(a[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = Node::combine(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int p, int value) {
        for (tree[p += n].apply(value), p >>= 1; p > 0; p >>= 1) {
            tree[p] = Node::combine(tree[p << 1], tree[p << 1 | 1]);
        }
    }

    Node query(int l, int r) {
        Node resL, resR;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = Node::combine(resL, tree[l++]);
            if (r & 1) resR = Node::combine(tree[--r], resR);
        }
        return Node::combine(resL, resR);
    }
};
