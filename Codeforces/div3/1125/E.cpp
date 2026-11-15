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
    int i,n; cin>>n;
    vi a(n),b(n);
    for(auto &w : a) cin>>w;
    for(auto &w : b) cin>>w;

    if(n==1){
        if(a[0]==b[0]) cout<<"2"<<endl;
        else cout<<"1"<<endl;
        return;
    }

    vvi dp1(n,vi(2));
    vvi dp2(n,vi(2));
    dp1[0][0]=0;
    dp1[0][1]=1;
    if(a[0]==b[0])dp1[0][1]++;
    for(i=1;i<n;i++){
        dp1[i][0]=dp1[i-1][1]+1;
        if(a[i]==b[i-1])dp1[i][0]++;
        dp1[i][1]=dp1[i][0]+1;
        if(a[i]==b[i])dp1[i][1]++;
    }
    dp2[n-1][0]=1;
    dp2[n-1][1]=0;
    if(a[n-1]==b[n-1]){
        dp2[n-1][0]=2;
        dp2[n-1][1]=0;
    }
    for(i=n-2;i>=0;i--){
        dp2[i][0]=dp2[i+1][1]+1;
        if(a[i]==b[i+1])dp2[i][0]++;
        dp2[i][1]=dp2[i+1][0]+1;
        if(b[i]==a[i+1]) dp2[i][1]++;
    }
    int resp=0;

    for(i=0;i<n;i++){
        resp=max(resp,dp1[i][0]+dp2[i][0]+dp2[i][1]);
    }
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
