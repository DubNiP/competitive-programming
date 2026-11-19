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

    int n,k; cin>>n>>k;
    vi v(n);
    for(auto &w : v) cin>>w;
    vi ps(n+1);
    ps[0]=0;
    for(int i=1;i<=n;i++) ps[i]=(ps[i-1]+v[i-1])%k;
    vi freq(k+5);
    int resp=0;
    for(int i=k+1;i<=n;i++){
        freq[ps[i-k-1]]++;
        resp+=freq[ps[i]];
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
