//TESTAR
vector<pair<int, ii>> edges;

int kruskal(int n) {
    int cost = 0;
    DSU dsu(n); 
    
    sort(all(edges));
    
    for (auto &[w, uv] : edges) {
        auto [u, v] = uv;
        if (dsu.join(u, v)) cost += w; 
    }
    
    return cost;
}
