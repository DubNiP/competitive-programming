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

    int n,m,i; cin>>m>>n;
    adj = vvi(2*n);
    tran = vvi(2*n);
    vis = vb(2*n,false);
    id = vi(2*n,-1);
    for(i=0;i<m;i++){
        int a,b; char f,s; 
        cin>>f>>a>>s>>b; a--;b--;

        if(f=='+'&&s=='+'){
            adj[a+n].pb(b);
            adj[b+n].pb(a);
            tran[b].pb(a+n);
            tran[a].pb(b+n);
        }
        if(f=='-'&&s=='+'){
            adj[a].pb(b);
            adj[b+n].pb(a+n);
            tran[b].pb(a);
            tran[a+n].pb(b+n);
        }
        if(f=='+'&&s=='-'){
            adj[b].pb(a);
            adj[a+n].pb(b+n);
            tran[a].pb(b);
            tran[b+n].pb(a+n);
        }
        if(f=='-'&&s=='-'){
            adj[a].pb(b+n);
            adj[b].pb(a+n);
            tran[b+n].pb(a);
            tran[a+n].pb(b);
        }
    }
    for(i=0;i<2*n;i++) if(!vis[i]) dfs(i);
    for(i=2*n-1;i>=0;i--) if(id[fila[i]]==-1) dfstran(fila[i],i+1);
    
    for(i=0;i<n;i++){
        if(id[i]==id[i+n]){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    for(i=0;i<n;i++){
        if(id[i]<id[i+n]) cout<<"+ ";
        else cout<<"- ";
    }

    
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}

