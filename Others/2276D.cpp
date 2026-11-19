#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back

#define all(x) x.begin(),x.end()
#define siz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

const int inf=2e18;
const int MOD=1e9+7;

vvi adj;

struct DSU {
    vi p,sz;
    DSU(int n) {
        p.resize(n);
        iota(all(p),0);
        sz.assign(n,1);
    }
    int find(int i) {
        if(p[i]==i) return i;
        return p[i]=find(p[i]);
    }
    bool join(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return false;
        if(sz[u] < sz[v]) swap(u,v);
        p[v] = u;
        sz[u] += sz[v];
        return true;
    }
    bool verify(){
        
        set<int> x;
        for(auto w : p){
            x.insert(find(w));
        }
        if(siz(x)!=1) return false;

        for(int i=0;i<siz(p);i++) if(siz(adj[i])==siz(p)-1) return true;
        return false;
    }
};

void solve() {

    
    int n,m; cin>>n>>m;
    adj=vvi(n);
    DSU pl(n);
    vb v(n);
    bool mark=false;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        v[a]=true;v[b]=true;
        adj[a].pb(b);
        adj[b].pb(a);
        if(!pl.join(a,b)) mark=true;
    }

    for(auto w : v){
        if(!w){
            cout<<"Brain Melt"<<endl;
            return;
        }
    }
 
    if(pl.verify()&&!mark){
        cout<<"2"<<endl;
    }
    else cout<<"Many"<<endl;
        

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
