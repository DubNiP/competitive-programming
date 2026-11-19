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
    int n,m; cin>>n>>m;

    vi v(n); for(auto &w : v) cin>>w;
    int resp=0;
    sort(all(v));
    vi diff(m+5);
    for(int i=0;i<n;i++){
        diff[1]++;
        diff[v[i]+1]--;
        if(v[i]%2==0){
            diff[v[i]/2]++;
            diff[v[i]/2+1]--;
        }
    }
    int cont=0;
    for(auto w : diff){
        //cout<<w<<" ";
        cont+=w;
        resp=max(resp,cont);
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
