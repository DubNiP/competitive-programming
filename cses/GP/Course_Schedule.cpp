#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

vvi transp;
vb vis;
vi stamp;
vi ord;
bool ok=true;

void dfstransp(int i){
    vis[i]=true;
    stamp[i]=0;
    for(auto w : transp[i]){
        if(!vis[w]) dfstransp(w);
        else if(stamp[w]==0) ok=false;
    }
    stamp[i]=1;
    ord.push_back(i);
}


void solve() {

    int i,m,n; cin>>n>>m;
    transp=vvi(n);
    vis=vb(n);
    stamp=vi(n,-1);

    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        transp[b].push_back(a);
    }
    for(i=0;i<n;i++) if(!vis[i]) dfstransp(i);
    if(ok) for(i=0;i<ord.size();i++) cout<<ord[i]+1<<" ";
    else cout<<"IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
