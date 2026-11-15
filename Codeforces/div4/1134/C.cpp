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
    vi v(n); for(auto &w : v) cin>>w;

    sort(all(v));

    deque<int> r;
    int li=0;
    bool b=true;
    for(i=n-1;i>=0;i--){
        b ? r.pb(v[i]) : r.push_front(v[i]);
        b=!b;
    }
    for(i=0;i<n;i++){
        if(i==0||i==n-1)li++;
        else if(r[i]>r[i-1]||r[i]>r[i+1]) li++;
    }
    cout<<li<<endl;
    for(auto w : r) cout<<w<<" ";
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
