#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int n,m,i;
vector<vector<int>>adj;
vector<int>comp;
vector<int>resp;

void dfs(int i,int c){
    comp[i]=c;
    for( auto w : adj[i]){
        if(!comp[w]) dfs(w,c);
    }
}

void dfsr(int i){
    if(i>=n) resp[i-n]=2;
    else resp[i]=1;
    for(auto w : adj[i]){
        int aux=w;
        if(aux>=n) aux-=n;
        if(!resp[aux]) dfsr(w);
    }
}

void solve() {
    cin>>n>>m;
    adj=vector<vector<int>>(2*n);
    comp=vector<int>(2*n,0);

    for(i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        b--;
        c--;
        if(a==1){
            adj[b].push_back(c);
            adj[c].push_back(b);
            adj[b+n].push_back(c+n);
            adj[c+n].push_back(b+n);
        }
        else{
            adj[b].push_back(c+n);
            adj[c].push_back(b+n);
            adj[b+n].push_back(c);
            adj[c+n].push_back(b);
        }
    }

    for(i=0;i<2*n;i++){
        if(!comp[i]) dfs(i,i+1);
    }
    
    for(i=0;i<n;i++){
        if(comp[i]==comp[i+n]){
            cout<<"-1\n";
            return;
        }
    }
    resp=vector<int>(n,0);
    for(i=0;i<n;i++){
        if(!resp[i]) dfsr(i);
    }
    for(i=0;i<n;i++) cout<<resp[i]<<" ";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}

