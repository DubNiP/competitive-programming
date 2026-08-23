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
    int i,n,q; cin>>n>>q;
    vi ps(n+1);
    ps[0]=0;

    for(i=1;i<=n;i++){
        int a; cin>>a;
        ps[i]=ps[i-1]+a;
    }
    while(q--){
        int l,r; cin>>l>>r;
        cout<<ps[r]-ps[l-1]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
