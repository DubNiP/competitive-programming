//TESTAR
vvi build_dag(int n, int sccs, const vi& id, const vvi& adj) {
    vvi dag(sccs);
    set<pair<int, int>> seen;
    
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (id[u] != id[v] && !seen.count({id[u], id[v]})) {
                seen.insert({id[u], id[v]});
                dag[id[u]].pb(id[v]);
            }
        }
    }
    return dag;
}
