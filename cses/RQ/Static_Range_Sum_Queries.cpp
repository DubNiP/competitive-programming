#include <bits/stdc++.h>

#define int long long
#define endl "\n"
using namespace std;

void solve(){
    int i,n,q; cin>>n>>q;
    vector<int> ps(n+1); 
    for(i=0;i<n;i++){
        int aux; cin>>aux;
        ps[i+1]=ps[i]+aux;
    }

    while(q--){
        int l,r; cin>>l>>r;
        cout<<ps[r]-ps[l-1]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
