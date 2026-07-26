#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;

vi v;
vi seg;

int build(int l,int r,int p){
    if(l==r) return seg[p]=v[l];
    int m=(l+r)/2;
    return seg[p]=build(l,m,2*p)+build(m+1,r,2*p+1);
}

int update(int i, int x, int l, int r, int p){
    if(i<l||i>r) return seg[p];
    if(l==r) return seg[p]=x;
    int m=(l+r)/2;
    return seg[p]=update(i,x,l,m,2*p)+update(i,x,m+1,r,2*p+1);
}

int query(int a, int b, int l, int r, int p){
    if(a>r || b<l) return 0;
    if(a<=l && b>=r) return seg[p];
    int m = (l+r)/2;
    return query(a,b,l,m,2*p)+query(a,b,m+1,r,2*p+1);
}

void solve() {

    int n,q; cin>>n>>q;
    v=vi(n);
    seg=vi(4*n+10);
    for(auto &w : v) cin>>w;

    build(0,n-1,1);
    while(q--){
        int z,a,b; cin>>z>>a>>b; a--;
        if(z==1) update(a,b,0,n-1,1);
        else{
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
