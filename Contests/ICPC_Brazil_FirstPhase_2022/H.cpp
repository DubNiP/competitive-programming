#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

vvi adj;
vvi transp;
vi ord;
vi id;
vb vis;
vvi segmented;

int resp=0;

vb sumid;
vb topo;
void verify(int i){
    for(auto w : segmented[i]) topo[w]=true;
    if(segmented[i].size()==0) sumid[i]=true;
}

void toposort(int i){
    vis[i]=true;
    for(auto w : adj[i]) if(!vis[w]) toposort(w);
    ord.pb(i);
}

void segm(int i,int idx){
    id[i]=idx;
    for(auto w : transp[i]){ 
        if(id[w]==-1) segm(w,idx);
        else if(id[w]!=id[i])segmented[id[w]].pb(id[i]);
    }
}


void solve(){

    int i,n,m; cin>>n>>m;
    adj=vvi(n);
    transp=vvi(n);
    vis=vb(n);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
        transp[b].pb(a);
    }

    for(i=0;i<n;i++){
        if(!vis[i]) toposort(i);
    }
    reverse(ord.begin(),ord.end());
    id=vi(n,-1);
    int idx=0;
    segmented=vvi(n);
    for(i=0;i<n;i++){
        if(id[ord[i]]==-1){
            segm(ord[i],idx);
            idx++;
        }
    }
    if(idx==1){
        cout<<0;
        return;
    }
    sumid = vb(idx);
    topo = vb(idx);
    int conts=0,contt=0;
    for(i=0;i<idx;i++) verify(i);
    for(i=0;i<idx;i++){
        if(sumid[i])conts++;
        if(!topo[i])contt++;
    }
    cout<<max(conts,contt);


    

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
