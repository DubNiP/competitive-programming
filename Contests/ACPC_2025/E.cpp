#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

void solve(){
    
    int n,i; cin>>n;
    vi v(n); for(auto &w : v) cin>>w;
    vi conf(n+1,-1);
    conf[n]=0;
    for(i=n-1;i>=0;i--){
        if(i+v[i]<n&&conf[i+v[i]+1]==0)conf[i]=1;
        else if(conf[i+1]==0)conf[i]=1;
        else conf[i]=0;
    }
    if(conf[0]==0) cout<<"NO\n";
    else cout<<"YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
