//TESTAR

struct Dijkstra {
    vi dist;
    
    Dijkstra(int s, const vii& adj) {
        dist.assign(adj.size(), INF);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        
        dist[s] = 0;
        pq.emplace(0, s);
        
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue; 
            
            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
};
