//TESTAR
struct LCA {
    int timer = 0, log_n;
    vvi up;
    vi in, out, prof;

    LCA(int n, int root, vvi& adj) {
        log_n = __lg(n) + 2; 
        up.assign(n, vi(log_n, root));
        in.resize(n); out.resize(n); prof.resize(n);
        dfs(root, root, 0, adj);
    }

    void dfs(int u, int p, int d, vvi& adj) {
        in[u] = ++timer;
        prof[u] = d;
        up[u][0] = p;
        
        for (int i = 1; i < log_n; i++) up[u][i] = up[up[u][i - 1]][i - 1];
        for (int v : adj[u]) if (v != p) dfs(v, u, d + 1, adj);

        out[u] = ++timer;
    }

    bool anc(int u, int v) { return in[u] <= in[v] && out[u] >= out[v]; }

    int get(int u, int v) {
        if (anc(u, v)) return u;
        if (anc(v, u)) return v;

        for (int i = log_n - 1; i >= 0; i--)
            if (!anc(up[u][i], v)) u = up[u][i];

        return up[u][0];
    }

    int dist(int u, int v) { return prof[u] + prof[v] - 2 * prof[get(u, v)]; }
};
