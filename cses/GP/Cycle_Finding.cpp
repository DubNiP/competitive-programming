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

vector<tuple<int,int,int>> edges;
vi dist;
vi resp;
vi pai;


void solve(){

    int i,n,m; cin>>n>>m;
    dist=vi(n+1);
    pai=vi(n+1);
    edges=vector<tuple<int,int,int>>(m);
    for(auto &[a,b,w] : edges) cin>>a>>b>>w;

    for(i=1;i<=n;i++) dist[i]=0;
    int p=-1;
    for(i=1; i<=n;i++){
        for(auto e : edges){
            int a,b,w;
            tie(a,b,w)=e;
            if(i==n&&dist[b]>dist[a]+w){
                p=b;
                pai[b]=a;
            }
            else if(dist[b]>dist[a]+w){
                dist[b]=dist[a]+w;
                pai[b]=a;
            }
        }
    }
    if(p==-1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(i=0;i<n;i++)p=pai[p];
        int aux=p;
        resp.pb(p);
        p=pai[p];
        while(p!=aux){
            resp.pb(p);
            p=pai[p];
        }
        resp.pb(p);
        reverse(all(resp));
        for(auto w : resp)cout<<w<<" ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
