#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define int ll
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

int MOD=1e9+7;

vvi adj;
vb vis;
vi fila;
void dfs(int i){
    vis[i]=true;
    for(auto w : adj[i]) if(!vis[w]) dfs(w);
    fila.pb(i);
}




void solve(){
    int n,m,i; cin>>n>>m;
    adj=vvi(n);
    vis = vb(n,false);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
    }

    for(i=0;i<n;i++) if(!vis[i]) dfs(i);

    vi cam(n,0);
    cam[0]=1;

    for(i=n-1;i>=0;i--){
        for(auto w : adj[fila[i]]) cam[w]=(cam[w]+cam[fila[i]])%MOD;
    }
    cout<<cam[n-1];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
