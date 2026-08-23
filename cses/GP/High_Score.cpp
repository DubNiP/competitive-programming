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


const int INF = 2e18;
const int MOD = 1e9+7;

vvi adj;
vi dist;
vb vis;
vector<tuple<int,int,int>> edges;

bool dfs(int i,int n){
    bool aux=false;
    vis[i]=true;
    if(i==n)return true;
    for(auto w : adj[i]){
        if(!vis[w]){
            aux=dfs(w,n);
            if(aux)return true;
        }
    }
    return false;
}

void solve(){
    
    int i,n,m; cin>>n>>m;
    edges=vector<tuple<int,int,int>>(m);
    adj=vvi(n+1);
    dist=vi(n+1);
    vis=vb(n+1);
    for(auto &[a,b,w] : edges) cin>>a>>b>>w;
    for(auto [a,b,w] : edges) adj[a].pb(b);
    for(i=1;i<=n;i++) dist[i]=INF;
    dist[1]=0;
    vi aux;
    for(i=1;i<=n;i++){
        for(auto e : edges){
            int a,b,w;
            tie(a,b,w)=e;
            if(dist[a]!=INF&&dist[b]>dist[a]-w&&i==n) aux.pb(b);
            if(dist[a]!=INF)dist[b]=min(dist[b],dist[a]-w);
        }
    }
    for(auto w : aux){
        if(dist[w]!=INF&&dfs(w,n)){
            cout<<"-1\n";
            return;
        }
    }
    cout<<-dist[n];

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
