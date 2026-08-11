#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


void solve() {
    int a,b,c; cin>>a>>b>>c;
    cout<<min(min(abs(a-b),abs(b-c)),abs(a-c))<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
