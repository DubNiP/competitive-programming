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
using ii = tuple<int,int,int>;
using vvi = vector<vector<int>>;
using vii = vector<vector<tuple<int,int,int>>>;


const int INF = 2e18;
const int MOD = 1e9+7;

vii adj;
vb vis;
vi veio;

struct Dijkstra{
    vi dist;
    vi resp;

    Dijkstra(int s,const vii&adj,int k){
        dist.assign(adj.size(),INF);
        priority_queue<ii,vector<ii>,greater<ii>>pq;
        dist[s]=0;
        pq.emplace(0,s,-1);
        k++;
        while(!pq.empty()&&k>0){
            auto [d,u,z] = pq.top();pq.pop();
           
            if(d > dist[u]) continue;
            k--;
            if(z!=-1)resp.pb(z);

            for(auto [v,w,y] : adj[u]){
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    pq.emplace(dist[v],v,y);
                }
            }
        }
        cout<<sz(resp)<<endl;
        for(auto w : resp) cout<<w<<" ";
    }
};

void solve(){
    int i,n,m,k; cin>>n>>m>>k;
    adj=vii(n);
    vis=vb(n);
    for(i=0;i<m;i++){
        int a,b,p; cin>>a>>b>>p; a--;b--;
        adj[a].pb(make_tuple(b,p,i+1));
        adj[b].pb(make_tuple(a,p,i+1));
    }
    Dijkstra d(0,adj,k);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
