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

struct kosaraju{
    int n,sccs=0;
    vvi adj, adj_t;
    vb vis;
    vi order,id,money;

    kosaraju(int n, vi v) : n(n),adj(n),adj_t(n),vis(n),id(n,-1),money(v){}
    

    void add_edge(int u,int v){
        adj[u].pb(v);
        adj_t[v].pb(u);
    }

    void dfs1(int u){
        vis[u]=true;
        for(int v : adj[u]) if(!vis[v]) dfs1(v);
        order.pb(u);
    }

    void dfs2(int u){
        vis[u]=true;
        id[u]=sccs;
        for(int v : adj_t[u]) if(!vis[v]) dfs2(v);
    }

    vi build(){
        for(int i=0;i<n;i++) if(!vis[i]) dfs1(i);

        vis.assign(n,false);
        reverse(all(order));

        for(int u:order){
            if(!vis[u]){
                dfs2(u);
                sccs++;
            }
        }
        vi nmon(sccs);
        for(int i=0;i<n;i++){
            nmon[id[i]]+=money[i];
        }
        return nmon;
    }
};

vvi build_dag(int n,int sccs, const vi& id, const vvi& adj){
    vvi dag(sccs);
    set<ii> seen;

    for(int u=0;u<n;u++){
        for(int v : adj[u]){
            if(id[u]!=id[v]&&!seen.count({id[u],id[v]})){
                seen.insert({id[u],id[v]});
                dag[id[u]].pb(id[v]);
            }
        }
    }
    return dag;
}

vi dp;

int dfs(vvi &g,int i,vi &mon){
    int points=mon[i];
    for(auto w : g[i]){
        if(dp[w]!=-1) points=max(points,mon[i]+dp[w]);
        else points=max(points,mon[i]+dfs(g,w,mon));
    }
    dp[i]=points;
    return points;
}

void solve(){

    int n,m; cin>>n>>m;
    vi mon(n); for(auto &w : mon) cin>>w;
    kosaraju ad(n,mon);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        ad.add_edge(a,b);
    }
    mon=ad.build();
    vvi g=build_dag(n,ad.sccs,ad.id,ad.adj);
    
    n=ad.sccs;
    vb nfont(n);
    dp=vi(n,-1);
    for(int i=0;i<n;i++){
        for(auto w : g[i]) nfont[w]=true;
    }
    int resp=0;
    for(int i=0;i<n;i++){
        if(!nfont[i]) resp=max(resp,dfs(g,i,mon));
    }
    cout<<resp<<endl;

    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
