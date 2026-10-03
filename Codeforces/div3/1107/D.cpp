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
    vi v1(n),diff(n);
    for(auto &w : v1) cin>>w;
    for(i=0;i<n;i++){
        cin>>diff[i];
        diff[i]-=v1[i];
    }
    for(i=0;i<n-1;i++){
        if(diff[i]<0){
            cout<<"NO"<<endl;
            return;
        }
        diff[i+1]+=diff[i];
    }
    if(diff[n-1]<0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
