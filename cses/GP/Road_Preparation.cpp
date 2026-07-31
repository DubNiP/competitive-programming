#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

vi id,sz;

int find(int x){
    if(id[x]==x) return x;
    return id[x]=find(id[x]);
}

void unite(int x,int y){
    int p=find(x),q=find(y);
    if(p==q) return;
    if(sz[p]>sz[q]) swap(p,q);
    id[p]=id[q];
    sz[q]+=sz[p];
}

void solve() {
    
    int n,m; cin>>n>>m;
    ll cost=0;
    sz=vi(n+1,1);
    id=vi(n+1);
    iota(id.begin(),id.end(),0);

    vector<tuple<int,int,int>>v(m);
    for( auto &[w,a,b] : v) cin>>a>>b>>w;
    sort(v.begin(),v.end());
    

    for( auto [w,a,b] : v){
        if(find(a)!=find(b)){
            unite(a,b);
            cost+=w;
        }
    }
    for(int i=1;i<=n;i++){
        if(find(1)!=find(i)){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    cout<<cost;


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
