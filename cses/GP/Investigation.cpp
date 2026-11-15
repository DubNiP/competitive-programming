#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;
using vii = vector<vector<ii>>;


const int INF = 2e18;
const int MOD = 1e9+7;
vii adj;
int n;

struct Dijkstra {
    vi dist, routes, min_e,max_e;

    Dijkstra(int s, const vii & adj){
        dist = vi(n,INF);
        routes= vi(n);
        min_e=vi(n,INF);
        max_e=vi(n);
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        dist[s]=0;
        routes[s]=1;
        min_e[s]=0;
        max_e[s]=0;
        pq.emplace(0,s);
        while(!pq.empty()){
            auto [d,u]=pq.top();pq.pop();
            if(d > dist[u]) continue;
            for(auto [v,w] : adj[u]){
                if(dist[v] > d+w){
                    dist[v]=d+w;
                    routes[v]=routes[u];
                    min_e[v]=min_e[u]+1;
                    max_e[v]=max_e[u]+1;
                    pq.emplace(dist[v],v);
                }
                else if(dist[v] == d+w){
                    routes[v]=(routes[v]+routes[u])%MOD;
                    max_e[v]=max(max_e[u]+1,max_e[v]);
                    min_e[v]=min(min_e[v],min_e[u]+1);
                }
            }
        }
        cout<<dist[n-1]<<" "<<routes[n-1]<<" "<<min_e[n-1]<<" "<<max_e[n-1];
    }
};

void solve(){

    int i,m; cin>>n>>m;
    adj=vii(n);
    for(i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c; a--;b--;
        adj[a].pb({b,c});
    }
    Dijkstra(0,adj);

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}

