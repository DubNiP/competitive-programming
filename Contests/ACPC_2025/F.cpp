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
vi v;
vvi adj;
vector<ii> resps;

void dfs(int i,int sum,int tam){
    sum+=v[i];
    resps.pb({sum,tam});
    for(auto w : adj[i]) dfs(w,sum,tam+1);
}

void solve(){
    int i,d,p,h; cin>>d>>p>>h;
    v=vi(d); for(auto &w : v) cin>>w;
    adj=vvi(d);
    vb rot(d,true);

    for(i=0;i<p;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
        rot[b]=false;
    }
    
    for(i=0;i<d;i++){
        if(rot[i]) dfs(i,0,1);
    }
    sort(all(resps));
    vector<ii>fin;
    fin.pb({0,0});
    int ant=0;
    for(i=0;i<sz(resps);i++){
        if(resps[i].f!=ant){
            fin.pb(resps[i]);
            ant=resps[i].f;
        }
    }
    while(h--){
        int c; cin>>c;
        auto it = upper_bound(all(fin),ii {c,INF});
        --it;
        cout<<it->f<<" "<<it->s<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
