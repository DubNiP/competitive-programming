#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;


vvi adj;
vi vis;

vi resp;
bool ok=false;

int bgn=-1;

void dfs(int i,int ant, int idx){
    vis[i]=idx;
    resp.push_back(i);
    for(auto w : adj[i]){
        if(vis[w]==vis[i]&&w!=ant&&!ok){
            resp.push_back(w);
            ok=true;
            bgn=w;
            return;
        }
        else if(!vis[w]&&!ok) dfs(w,i,idx);
    }
    if(!ok) resp.pop_back();
}


void solve() {

    int n,m,i; cin>>n>>m;
    adj=vvi(n);
    vis=vi(n);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    for(i=0;i<n;i++){
        if(vis[i]==0&&!ok){
            resp.clear();
            dfs(i,-1,i+1);
        }
    }
        
    if(!ok) cout<<"IMPOSSIBLE";
    else{
        bool up=false;
        vi at;
        for(i=0;i<resp.size();i++){
            if(resp[i]==bgn) up=true;
            if(up) at.push_back(resp[i]); 
        }
        cout<<at.size()<<"\n";
        for(i=0;i<at.size();i++) cout<<at[i]+1<<" ";
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
