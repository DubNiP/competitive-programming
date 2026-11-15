#include <bits/stdc++.h>
#define int long long
using namespace std;
using vi=vector<int>;

void solve(){
    int n,i; cin>>n;
    vi a(n),b(n+1); for(auto &w : a) cin>>w;
    sort(a.begin(),a.end());
    b[0]=0;
    for(i=1;i<=n;i++){
        int aux; cin>>aux;
        b[i]=b[i-1]+aux;
    }

    int resp=0;

    for(i=0;i<n;i++){
        int espadas=n-i;
        auto t =upper_bound(b.begin(),b.end(),espadas);
        
        resp=max(resp,(t-b.begin()-1) * a[i]);
    }
    cout<<resp<<endl;
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
