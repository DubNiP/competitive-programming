// TESTAR
struct TwoSat {
    int n;
    Kosaraju k;
    vb ans;

    TwoSat(int n) : n(n), k(2 * n), ans(n) {}

    void add_clause(int u, int v) {
        k.add_edge(u ^ 1, v); // Se nao u, entao v
        k.add_edge(v ^ 1, u);
    }

    bool build() {
        k.build();
        
        for (int i = 0; i < n; i++) {
            if (k.id[2 * i] == k.id[2 * i + 1]) return false;
            ans[i] = k.id[2 * i] > k.id[2 * i + 1];
        }
        return true;
    }
};
