#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
int INF = 1e18;

void solve() {
    int n,m,q,i,j,k; cin>>n>>m>>q;
    vvi adj(n,vi(n,INF));
    for(i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[b][a],c);
    }
    for (i=0;i<n;i++) adj[i][i] = 0;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    while(q--){
        int x,y; cin>>x>>y; x--;y--;
        adj[x][y]!=INF ? cout<<adj[x][y]<<"\n" : cout<<"-1\n";
    }


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
