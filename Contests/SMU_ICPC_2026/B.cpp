#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,k,m; cin>>n>>k>>m;
    if(k==0) cout<<(m-1)<<"\n";
    else cout<<(m-1)+(k-1)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
