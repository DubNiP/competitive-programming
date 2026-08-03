#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

vvi adj,tran;
vb vis;
vi fila,id;

void dfs(int i){
    vis[i]=true;
    for(auto w : adj[i]) if(!vis[w]) dfs(w);
    fila.pb(i);
}

void dfstran(int i, int num){
    id[i]=num;
    for(auto w : tran[i]) if(id[w]==-1) dfstran(w,num);
}

void solve(){

    int n,m,i; cin>>n>>m;
    adj = vvi(n);
    tran = vvi(n);
    vis = vb(n,false);
    id = vi(n,-1);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
        tran[b].pb(a);
    }

    for(i=0;i<n;i++) if(!vis[i]) dfs(i);

    int lbl=1;
    for(i=n-1;i>=0;i--) if(id[fila[i]]==-1){
        dfstran(fila[i],lbl);
        lbl++;
    }
    
    cout<<lbl-1<<"\n";
    for(i=0;i<n;i++) cout<<id[i]<<" ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
