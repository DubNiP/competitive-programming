#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
#define int long long
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


int INF= 1e18;

vvi adj;
vi value;
vi resp;
vb vis;

void dfs(int w,vi &seq){
    vis[w]=true;
    auto it=lower_bound(seq.begin(),seq.end(),value[w]);
    int idx = it-seq.begin();
    int save=seq[idx];
    if(value[w]<seq[idx]) seq[idx]=value[w];
    for(auto u : adj[w]){
        if(!vis[u]) dfs(u,seq);
    }
    resp[w]=(lower_bound(seq.begin(),seq.end(),INF)-seq.begin());
    seq[idx]=save;
}

void solve(){
    
    int i,n; cin>>n;
    vi seq(n,INF);

    adj=vvi(n);
    value=vi(n);
    resp=vi(n,-1);
    vis=vb(n);
    for(i=1;i<n;i++){
        int a; cin>>a; a--;
        adj[a].pb(i);
        adj[i].pb(a);
    }
    for(auto &w : value) cin>>w;

    dfs(0,seq);

    for(i=1;i<n;i++) cout<<resp[i]<<" ";


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
