#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
#define int ll
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

vi v,p,diff;

int build(int l, int r,int i){
    if(l==r) return p[i]=diff[l-1];
    int mid=(l+r)/2;
    return p[i] = build(l,mid,2*i) + build(mid+1,r,2*i+1);
}

int update(int v, int idx, int l, int r, int i){
    if(idx<l||idx>r) return p[i];
    if(l==r) return p[i]+=v;
    int mid = (l+r)/2;
    return p[i]=update(v,idx,l,mid,i*2)+update(v,idx,mid+1,r,i*2+1);
}

int query(int l, int r, int a, int b, int idx){
    if(b<l||a>r) return 0;
    if(a<=l&&b>=r) return p[idx];
    int mid=(l+r)/2;
    return query(l,mid,a,b,idx*2)+query(mid+1,r,a,b,idx*2+1);
}


void solve(){
    int n,q,i; cin>>n>>q;
    v = vi(n);
    diff = vi(n);
    cin>>v[0];
    diff[0]=v[0];
    for(i=1;i<n;i++){
        cin>>v[i];
        diff[i]=v[i]-v[i-1];
    }
    p=vi(4*n+10);

    build(1,n,1);
    while(q--){
        int a,b,c,d; cin>>a>>b; b--;
        if(a==1){
            cin>>c>>d;
            update(d,b,0,n-1,1);
            update(-d,c,0,n-1,1);
        }
        else{
            cout<<query(0,n-1,0,b,1)<<"\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
