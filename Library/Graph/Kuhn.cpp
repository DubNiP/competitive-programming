//Algoritmo de Kuhn, complexidade V*E
struct Kuhn {
    int n, m;
    vvi adj;
    vi match;
    vi vis;

    Kuhn(int n, int m) : n(n), m(m), adj(n), match(m, -1), vis(n, 0) {}

    void add_edge(int u, int v) {adj[u].pb(v);}

    bool dfs(int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (match[v] == -1 || (!vis[match[v]] && dfs(match[v]))) {
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int max_matching() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            fill(all(vis), 0);
            if (dfs(i)) ans++;
        }
        return ans;
    }
};


