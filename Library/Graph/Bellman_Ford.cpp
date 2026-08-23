struct BellmanFord {
    int n;
    vector<tuple<int, int, int>> edges;
    vi dist;
    vi pai;

    BellmanFord(int n) : n(n), dist(n + 1, INF), pai(n + 1, -1) {}

    void add_edge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }
    
    bool run(int z) {
        dist.assign(n + 1, INF);
        pai.assign(n + 1, -1);
        dist[z] = 0;
        
        int relax = -1;

       
        for (int i = 1; i <= n; i++) {
            relax = -1;
            for (auto [u, v, w] : edges) {
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pai[v] = u;
                    relax = v;
                }
            }
        }
       
        return relax != -1; 
    }
};
