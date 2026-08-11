#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int n,a; cin>>n>>a;
    vi v(n); for(auto &w : v) cin>>w;
    int resp=0;
    for(int i=0;i<n;i++) if(a>=v[i]) resp++;
    cout<<resp;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
