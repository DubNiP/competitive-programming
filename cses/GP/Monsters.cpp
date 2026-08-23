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

vector<string> adj;
vector<string> resp;
vector<vector<ii>> mon;
vector<vector<pair<bool,bool>>> vis;
queue<tuple<int,int,bool>>fila;

vector<ii> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool can(int x,int y,int n,int m,bool b){
    if(b&&x>=0&&x<n&&y>=0&&y<m&&adj[x][y]=='.'&& !vis[x][y].f) return true;
    if(!b&&x>=0&&x<n&&y>=0&&y<m&&adj[x][y]=='.'&&!vis[x][y].s) return true;
    return false;
}

void solve(){
    int i,j,n,m; cin>>n>>m;
    adj=vector<string>(n,string(m,'!'));
    resp=adj;
    mon=vector<vector<ii>>(n,vector<ii>(m,{INF,INF}));
    vis=vector<vector<pair<bool,bool>>>(n,vector<pair<bool,bool>>(m));

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>adj[i][j];
            if(adj[i][j]=='M'){
                fila.push({i,j,0});
                mon[i][j].s=0;
            }
            if(adj[i][j]=='A'){
                fila.push({i,j,1});
                mon[i][j].f=0;
            }
        }
    }

    while(sz(fila)!=0){
        tuple<int,int,bool> aux=fila.front();
        fila.pop();
        bool b=get<2>(aux);
        int x=get<0>(aux),y=get<1>(aux);
        for(auto w : dir){
            int xx=x+w.f;
            int yy=y+w.s;
            if(can(xx,yy,n,m,b)){
                if(b)vis[xx][yy].f=true;
                else vis[xx][yy].s=true;
                fila.push({xx,yy,b});
                if(b){
                    if(w.f==1&&w.s==0) resp[xx][yy]='D';
                    else if(w.f==0&&w.s==1) resp[xx][yy]='R';
                    else if(w.f==-1&&w.s==0) resp[xx][yy]='U';
                    else resp[xx][yy]='L';
                    mon[xx][yy].f=mon[x][y].f+1;
                }
                else mon[xx][yy].s=mon[x][y].s+1;
            }
        }
    }

    int xresp=-1,yresp=-1;

    for(i=0;i<n;i++){
        if((adj[i][0]=='.'||adj[i][0]=='A')&&mon[i][0].f<mon[i][0].s){
            xresp=i;
            yresp=0;
            break;
        }
        if((adj[i][m-1]=='.'||adj[i][m-1]=='A')&&mon[i][m-1].f<mon[i][m-1].s){
            xresp=i;
            yresp=m-1;
            break;
        }
    }
    for(i=0;i<m;i++){
        if((adj[0][i]=='.'||adj[0][i]=='A')&&mon[0][i].f<mon[0][i].s){
            xresp=0;
            yresp=i;
            break;
        }
        if((adj[n-1][i]=='.'||adj[n-1][i]=='A')&&mon[n-1][i].f<mon[n-1][i].s){
            xresp=n-1;
            yresp=i;
            break;
        }
    }
    if(xresp==-1) cout<<"NO\n";
    else{
        vis=vector<vector<pair<bool,bool>>>(n,vector<pair<bool,bool>>(m));
        string gt;
        cout<<"YES\n";
        cout<<mon[xresp][yresp].f<<"\n";
        while(adj[xresp][yresp]!='A'){
            char c=resp[xresp][yresp];
            gt.pb(c);
            if(c=='R') yresp--;
            else if(c=='L') yresp++;
            else if(c=='U') xresp++;
            else xresp--;
        }
        reverse(all(gt));
        cout<<gt;

    }



    

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
