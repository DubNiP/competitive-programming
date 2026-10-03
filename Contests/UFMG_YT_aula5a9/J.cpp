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

vvi adj1,adj2;
vi dist1,dist2;
vb vis1,vis2;
int n,m;
int bfs(){
    vis1[0]=true; dist1[0]=0;
    vis2[0]=true; dist2[0]=0;
    queue<int>fila;
    fila.push(0);
    while(!fila.empty()){
        int p=fila.front();
        fila.pop();
        for(int i=0;i<n;i++){
            if(adj1[p][i]==0)continue;
            if(!vis1[i]){
                vis1[i]=true;
                dist1[i]=dist1[p]+1;
                fila.push(i);
            }
        }
    }
    fila.push(0);
    while(!fila.empty()){
        int p=fila.front();
        fila.pop();
        for(int i=0;i<n;i++){
            if(adj2[p][i]==0)continue;
            if(!vis2[i]){
                vis2[i]=true;
                dist2[i]=dist2[p]+1;
                fila.push(i);
            }
        }
    }

    if(dist1[n-1]==0||dist2[n-1]==0) return -1;
    return max(dist1[n-1],dist2[n-1]);
    

}

void solve(){

    int i,j; cin>>n>>m;
    adj1=vvi(n,vi(n,0));
    adj2=vvi(n,vi(n));
    dist1=vi(n);
    dist2=vi(n);
    vis1=vb(n);
    vis2=vb(n);
    for(i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj1[a][b]=1;
        adj1[b][a]=1;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j&&adj1[i][j]==0) adj2[i][j]=1;
        }
    }
    cout<<bfs()<<endl;
    


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
