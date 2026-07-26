#include <bits/stdc++.h>
#define int ll
#define f first
#define s second
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;
using vvii = vector<vector<ii>>;
int INF = 1e18;
vvii adj;
vi dist;


void solve(){
    int n,m,i; cin>>n>>m;
    adj=vvii(n);
    dist=vi(n,INF);
    for(i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        adj[a].push_back({b,c});
    }
    
    dist[0]=0;
    priority_queue<ii>fila;
    fila.push({0,0});
    while(fila.size()!=0){
        ii aux = fila.top();
        fila.pop();
        int w=-aux.f, v=aux.s;
        if(w>dist[v]) continue;
        for(auto [x,y] : adj[v]){
            if(w+y<dist[x]){
                dist[x]=w+y;
                fila.push({-(w+y),x});
            }
        }
    }
    for(auto w : dist) cout<<w<<" ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
