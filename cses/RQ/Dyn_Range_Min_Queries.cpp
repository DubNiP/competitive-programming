#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
int INF = 1e10;


vector<int>seg(1e6);
vector<int>v;

int build(int p,int l, int r){
    if(l==r) return seg[p]=v[l];
    int m=(l+r)/2;
    return seg[p]=min(build(p*2,l,m),build(p*2+1,m+1,r));
}

int query(int a, int b, int l,int r,int p){
    if(b<l || a>r) return INF;
    if(a<=l && b>=r) return seg[p];
    int m=(l+r)/2;
    return min(query(a,b,l,m,2*p),query(a,b,m+1,r,2*p+1));
}

int update(int x,int i,int l, int r, int p){
    if(i < l || r < i) return seg[p];
    if(l==r) return seg[p]=x;
    int m=(l+r)/2;
    return seg[p]=min(update(x,i,l,m,2*p),update(x,i,m+1,r,2*p+1));
}


void solve() {

    int n,q; cin>>n>>q;
    v=vector<int>(n);
    for(auto &w : v) cin>>w;
    build(1,0,n-1);

    while(q--){
        int z,a,b; cin>>z>>a>>b; a--;
        if(z==1) update(b,a,0,n-1,1);
        else {
            b--;
            cout<<query(a,b,0,n-1,1)<<"\n";
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
