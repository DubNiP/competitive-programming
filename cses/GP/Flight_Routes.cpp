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
int n,k;

struct Dijkstra {
    vvi dist;
    priority_queue<int> resps;

    Dijkstra(int s, const vii & adj){
        dist = vvi(n,vi(k));
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        dist[s][0]=0;
        pq.emplace(0,s);
        while(!pq.empty()){
            auto [d,u]=pq.top();pq.pop();
            if(d > dist[u]) continue;

            for(auto [v,w] : adj[u]){
                if(dist[v][sz(dist[v]-1)] > d+w){
                    dist[v][]=d+w;
                    pq.emplace(dist[v][],v);
                }
            }
        }
        vi resp; 
        while(k--){
            resp.pb(resps.top());
            resps.pop();
        }
        reverse(all(resp));
        for(auto w : resp) cout<<w<<" ";
    }
};

void solve(){

    int i,m; cin>>n>>m>>k;
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
