#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll i,n;
    cin>>n;
    vector<ll>v(n);
    for(auto &w : v) cin>>w;
    v[1]= v[0]+v[1]-1;
    for(i=1;i<n;i++){
        if(v[i]<=i){
            cout<<"NO\n";
            return;
        }
        if(i!=n-1) v[i+1]=v[i]+v[i+1]-i-1;
    }
    cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
