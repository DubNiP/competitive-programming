// NAO TESTADO E CONHECIMENTO BAIXO
struct SparseTable {
    int n, K;
    vector<vector<ii>> st;

    inline ii f(ii l, ii r) { return std::min(l, r); }

    SparseTable(const vi& a) {
        n = sz(a);
        K = __lg(n) + 1;
        st.assign(K, vector<ii>(n));

        for (int i = 0; i < n; i++) st[0][i] = {a[i], i};

        for (int i = 1; i < K; i++) 
            for (int j = 0; j + (1 << i) <= n; j++) 
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    ii query(int L, int R) {
        int k = __lg(R - L + 1);
        return f(st[k][L], st[k][R - (1 << k) + 1]);
    }
};

