struct LCA {
    int timer = 0, log_n;
    vvi up;
    vi in, out, prof;

    LCA(int n, int root, vvi& adj) {
        log_n = __lg(n) + 2; 
        up.assign(log_n, vi(n, root));
        in.resize(n); out.resize(n); prof.resize(n);
        dfs(root, root, 0, adj);
    }

    void dfs(int u, int p, int d, vvi& adj) {
        in[u] = ++timer;
        prof[u] = d;
        
        up[0][u] = p;
        
        for (int i = 1; i < log_n; i++) {
            up[i][u] = up[i - 1][up[i - 1][u]];
        }
        
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, d + 1, adj);
        }

        out[u] = ++timer;
    }

    bool anc(int u, int v) { 
        return in[u] <= in[v] && out[u] >= out[v]; 
    }

    int get(int u, int v) {
        if (anc(u, v)) return u;
        if (anc(v, u)) return v;

        for (int i = log_n - 1; i >= 0; i--) {
            if (!anc(up[i][u], v)) {
                u = up[i][u];
            }
        }
        return up[0][u];
    }

    int dist(int u, int v) { return prof[u] + prof[v] - 2 * prof[get(u, v)]; }
};
