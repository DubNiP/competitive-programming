#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back

#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

const int inf=2e18;
const int MOD=1e9+7;

void solve() {
    int n,i; cin>>n;
    vi v(n); for(auto &w : v) cin>>w;
    if(n==1){
        cout<<"-1\n";
        return;
    }
    int cont=0;
    int uns=0;
    if(v[0]==0) cont++;
    if(v[n-1]==0) cont++;
    for(i=0;i<n;i++){
        if(v[i]==0) uns++;
    }
    if(uns<2){
        cout<<"-1"<<endl;
        return;
    }
    cout<<2-cont<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
