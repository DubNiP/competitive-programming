//TESTAR
struct Kosaraju {
    int n, sccs = 0;
    vvi adj, adj_t;
    vb vis;
    vi order, id;

    Kosaraju(int n) : n(n), adj(n), adj_t(n), vis(n, false), id(n, -1) {}

    void add_edge(int u, int v) {
        adj[u].pb(v);
        adj_t[v].pb(u);
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v : adj[u]) if (!vis[v]) dfs1(v);
        order.pb(u);
    }

    void dfs2(int u) {
        vis[u] = true;
        id[u] = sccs;
        for (int v : adj_t[u]) if (!vis[v]) dfs2(v);
    }

    void build() {
        for (int i = 0; i < n; i++) if (!vis[i]) dfs1(i);
        
        vis.assign(n, false);
        reverse(all(order)); 
        
        for (int u : order) {
            if (!vis[u]) {
                dfs2(u);
                sccs++; 
            }
        }
    }
};
