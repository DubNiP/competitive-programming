#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
vvi grafo;
vb vis;
vb color;
bool imp=false;

void dfs(int i,bool p){
    vis[i]=true;
    color[i]=p;
    for(auto w : grafo[i]){
        if(!vis[w]) dfs(w,!p);
        else if(color[i]==color[w]) imp=true;
    }
}

void solve() {
    int n,m,i; cin>>n>>m;
    grafo=vvi(n);
    vis=vb(n);
    color=vb(n);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for(i=0;i<n;i++){
        if(!vis[i]) dfs(i,true);
    }
    if(imp){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(i=0;i<n;i++) color[i]==true ? cout<<"1 " : cout<<"2 ";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
