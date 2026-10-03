#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

vvi adj;
vi cor;
vb vis;
vvi dist;
int n,m,s,k;

void bfs(int c){
    vis=vb(n);
    int i;
    queue<int>fila;
    for(i=0;i<n;i++){
        if(cor[i]==c){
            fila.push(i);
            dist[i][c]=0;
            vis[i]=true;
        }
    }

    while(!fila.empty()){
        int aux=fila.front(); fila.pop();
        for(auto w : adj[aux]){
            if(!vis[w]){
                vis[w]=true;
                dist[w][c]=dist[aux][c]+1;
                fila.push(w);
            }
        }
    }
}

void solve(){
    
    int i; cin>>n>>m>>k>>s;
    adj = vvi(n);
    dist = vvi(n,vi(k,INF));
    cor = vi(n);
    vis = vb(n);
    for(i=0;i<n;i++){
        int aux; cin>>aux;
        cor[i]=aux-1;
    }

    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(i=0;i<k;i++){
        bfs(i);
    }

    for(i=0;i<n;i++) sort(all(dist[i]));
    int cont=0;
    for(i=0;i<n;i++){
        for(int j=0;j<s;j++){
            cont+=dist[i][j];
        }
        cout<<cont<<" ";
        cont=0;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
