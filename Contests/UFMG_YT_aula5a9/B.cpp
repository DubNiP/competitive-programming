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
    
    int i,n; cin>>n;
    vi a(n),b(n);
    for(auto &w:a) cin>>w;
    for(auto &w:b) cin>>w;

    vector<ii>dp(n);
    dp[0].f=a[0];
    dp[0].s=b[0];
    if(n>1)dp[1].f=a[1]+dp[0].s;
    if(n>1)dp[1].s=b[1]+dp[0].f;
    for(i=2;i<n;i++){
        dp[i].f=a[i]+max(dp[i-1].s,max(dp[i-2].f,dp[i-2].s));
        dp[i].s=b[i]+max(dp[i-1].f,max(dp[i-2].f,dp[i-2].s));
    }
    cout<<max(dp[n-1].f,dp[n-1].s)<<endl;


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
