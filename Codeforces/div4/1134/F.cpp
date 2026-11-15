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
    int n; cin>>n;
    vi v(n);
    vi resp(n);
    vb used(n);
    for(auto &w : v) cin>>w;

    for(int i=0;i<n;i++){
        if(n+v[i]-i-1>=n||n+v[i]-i-1<0||used[n+v[i]-i-1]){
            cout<<"-1\n";
            return;
        }
        resp[n+v[i]-i-1]=i+1;
        used[n+v[i]-i-1]=true;
    }
    for(auto w : resp) cout<<w<<" ";
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
