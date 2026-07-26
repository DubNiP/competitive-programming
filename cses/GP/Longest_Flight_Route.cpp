#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi= vector<vi>;
using vb = vector<bool>;

vvi adj;
vvi rev;
vi dist;
vb vis;

vi topo;
vi resp;

void top_sort(int i){
    vis[i]=true;
    for(auto w : rev[i]) if(!vis[w]) top_sort(w);
    topo.push_back(i);
}

void cdist(){
    for(int i=0;i<topo.size();i++){
        for(auto w : adj[topo[i]]){
            if(dist[topo[i]]==0) continue;
            dist[w] = max(dist[topo[i]]+1,dist[w]);
        }
    }
}

void dfsrev(int i){
    resp.push_back(i);
    if(dist[i]==1) return;
    for(auto w : rev[i]){
        if(dist[w]==dist[i]-1){ 
            dfsrev(w);
            return;
        }
    }
}


void solve() {
    int n,m,i; cin>>n>>m;
    adj = vvi(n);
    rev = vvi(n);
    dist = vi(n,0);
    vis = vb(n);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    top_sort(n-1);
    bool ok=false;
    for(auto w : topo) if(w==0)ok=true;
    if(!ok){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    dist[0]=1;
    cdist();
    cout<<dist[n-1]<<"\n";
    dfsrev(n-1);
    reverse(resp.begin(),resp.end());
    for(i=0;i<resp.size();i++) cout<<resp[i]+1<<" ";


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
