#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,resp=0;
    cin>>n;
    vector<ll>v(n);
    for(auto &w : v) cin>>w;
    for(int i=1;i<n;i++){
        resp+=max((ll)0,v[i-1]-v[i]);
        v[i]=max(v[i],v[i-1]);
    }
    cout<<resp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
