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
using vvvi = vector<vector<vector<char>>>;

const int INF = 2e18;
const int MOD = 1e9+7;
int l,n,m;

vvvi adj;
vector<vvi> vis;
vector<ii> ord={{1,0},{0,1},{-1,0},{0,-1}};

bool valido(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m) return true;
    return false;
}

void dfs(int c,int x,int y){
    if(adj[c][x][y]=='#')return;
    vis[c][x][y]=1;
    if(c>0&&!vis[c-1][x][y]) dfs(c-1,x,y);
    if(c<l-1&&!vis[c+1][x][y]) dfs(c+1,x,y);
    for(auto [a,b] : ord){
        int x1=x+a,y1=y+b;
        if(valido(x1,y1)&&!vis[c][x1][y1])dfs(c,x1,y1);
    }
}

void solve(){

    int i,j,k; cin>>l>>n>>m;
    adj=vvvi(l,vector<vector<char>>(n,vector<char>(m,'?')));
    vis = vector<vvi>(l,vvi(n,vi(m,0)));
    for(i=0;i<l;i++){
        for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                cin>>adj[i][j][k];
            }
        }
    }
    int x,y; cin>>x>>y; x--;y--;
    dfs(0,x,y);
    int resp=0;
    for(i=0;i<l;i++){
        for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                if(vis[i][j][k]) resp++;
            }
        }
    }
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
