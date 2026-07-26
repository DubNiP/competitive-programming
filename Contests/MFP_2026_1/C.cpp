#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a,b;
    cin>>a>>b;
    cout<<max(a*(b/7),b*(a/7));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}


