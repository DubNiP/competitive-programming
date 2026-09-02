#include <bits/stdc++.h>

#define int long long

#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define endl "\n"

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;
using iii = tuple<int, int, int>;

const int INF = 2e18;
const int MOD = 1e9+7ll;

struct Dijkstra {
    vvi dist;

    Dijkstra(int s, const vector<vector<tuple<int,int,bool>>>& adj){
        dist.assign(adj.size(),vector<int>(11,INF));
        priority_queue<iii,vector<iii>,greater<iii>> pq;
        dist[s][0]=0;
        pq.push({0,s,0});

        while(!pq.empty()){
            auto [d,u,dp] = pq.top();pq.pop();
            assert(u < adj.size());
            if (d > dist[u][dp]) continue;
            for(auto [v,w,bol] : adj[u]){
                assert(v < adj.size());
                if (!bol) {
                    assert(dp <= 10);
                    if (dist[v][dp] > d + w) {
                        dist[v][dp] = d + w;
                        pq.push({dist[v][dp], v, dp});
                    }
                } else {
                    if (dp + 1 > 10) continue;
                    assert(dp+1 <= 10);
                    if (dist[v][dp+1] > d + w) {
                        dist[v][dp+1] = d + w;
                        pq.push({dist[v][dp+1], v, dp+1});
                    }
                }
            }
        }
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<tuple<int, int, bool>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, r1, r2;
        cin >> a >> b >> r1 >> r2;
        a--; b--;
        if (r1 != -1) {
            adj[a].pb({b, r1, false});
            adj[b].pb({a, r1, false});
        }
        if (r2 != -1) {
            adj[a].pb({b, r2, true});
            adj[b].pb({a, r2, true});
        }
    }
    Dijkstra d(0, adj);
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = min(d.dist[n-1][i], ans);
    }
    cout << ans << "\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

