#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define push_back pb
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

int INF = 1e11;


                                          //CÓDIGO ERRADO.
vector<vector<ii>> adj;
vector<ii> dist;

void dijkstra(){
    priority_queue<ii>fila;
    fila.push({0,0});
    while(fila.size()!=0){
        int w = -fila.f, i = fila.s;
        fila.pop();
        if(dist[i].f<=w) continue;
        dist[i].f=w;
        dist[i].s
        for(auto [a,b] : adj[i]){
            fila.push({-b,a});
        }

    }
}

void solve() {
    int n,m,i; cin>>n>>m;
    adj=vector<vector<ii>>(n);
    dist=vector<ii>(n,{INF,INF});
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb({b,i);
        adj[b].pb({a,i);
    }
    dist[0]=0;
    dijkstra();
    for(i=1;i<n;i++) cout<<expbin(i)<<" ";


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
