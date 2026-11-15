#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

void solve(){
    int n, m; cin >> n >> m;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cs = 0;
    vi vis(n);
    auto dfs = [&](auto &&dfs, int u) -> void{
        vis[u] = 1;
        for(auto v: adj[u]){
            if(!vis[v]) dfs(dfs, v);
        }
    };
    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(dfs, i), cs++;
    }
    int c = 0;
    vis = vi(n);
    vvi colors(cs);
    auto dfs2 = [&](auto &&dfs2, int u, int c) -> void{
        vis[u] = 1;
        colors[c].push_back(u);
        for(auto v: adj[u]){
            if(!vis[v]) dfs2(dfs2, v, c);
        }
    };
    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs2(dfs2, i, c++);
    }
    priority_queue<ii> pq;
    for(int i = 0; i < cs; i++){
        if(colors[i].size() > 0) pq.push(ii(colors[i].size(), i));
    }
    vii ans;
    while(pq.size() > 1){
        auto [sz1, i1] = pq.top(); pq.pop();
        auto [sz2, i2] = pq.top(); pq.pop();
        ans.push_back(ii(colors[i1].back(), colors[i2].back()));
        colors[i1].pop_back();
        colors[i2].pop_back();
        if(colors[i1].size() > 0) pq.push(ii(colors[i1].size(), i1));
        if(colors[i2].size() > 0) pq.push(ii(colors[i2].size(), i2));
    }
    cout << (int)ans.size() << "\n";
    for(auto &[u, v]: ans) cout << u << " " << v << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

