#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back

#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

const int inf=2e18;
const int MOD=1e9+7;

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
        u=find(u);
        v=find(v);
        if(u==v) return false;
        if(sz[u]<sz[v]) swap(u,v);
        p[v]=u;
        sz[u]+=sz[v];
        return true;
    }
};

void solve() {
    int i,n,m; cin>>n>>m;
    DSU conj(n+1);
    vi v(n); for(auto &w:v) cin>>w;
    vi diffxor(n+1);
    diffxor[0]=v[0];
    for(i=1;i<n;i++) diffxor[i]=v[i-1]^v[i];
    diffxor[n]=v[n-1];

    for(i=0;i<m;i++){
        int a,b; cin>>a>>b;a--;
        conj.join(a,b);
    }
    
    vi resp(n+1);
    for(i=0;i<=n;i++){
        if(diffxor[i]==1) resp[conj.find(i)]++;
    }
    for(i=0;i<=n;i++){
        if(resp[i]%2==1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
