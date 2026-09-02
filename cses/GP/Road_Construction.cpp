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

struct DSU {
    vi p,sz;
    DSU(int n){
        p.resize(n);
        iota(all(p),0);
        sz.assign(n,1);
    }
    int find(int i){
        if(p[i]==i) return i;
        return p[i]=find(p[i]);
    }
    bool join(int u,int v){
        u = find(u);
        v = find(v);
        if(u==v) return false;
        if(sz[u] < sz[v]) swap(u,v);
        p[v]=u;
        sz[u]+=sz[v];
        return true;
    }
    int find_sz(int i){
        return sz[i];
    }
};


void solve(){
    int i,n,m; cin>>n>>m;
    int resp1=n,resp2=1;
    DSU se(n);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        if(se.join(a,b)){
            resp1--;
            a=se.find(a);
            resp2=max(resp2,se.find_sz(a));
        }
        cout<<resp1<<" "<<resp2<<endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
