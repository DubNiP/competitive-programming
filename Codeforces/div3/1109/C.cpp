#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int i,j,n,x,y;
    cin>>n>>x>>y;
    vector<int>v(n);
    for(auto &w : v) cin>>w;

    int z=gcd(x,y);
    for(i=0;i<n;i++){
        if(i==v[i]-1) continue;
        if(abs(i-(v[i]-1))%z!=0){
            cout<<"NO\n";
            return;
        }
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
