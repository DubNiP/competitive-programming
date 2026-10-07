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
    vi sor=v;
    sort(all(sor));
    vi ps1(n+1), ps2(n+1);
    ps1[0]=ps2[0]=0;

    for(i=1;i<=n;i++){
        ps1[i]=ps1[i-1]+v[i-1];
        ps2[i]=ps2[i-1]+sor[i-1];
    }
    int q; cin>>q;
    while(q--){
        int a,l,r; cin>>a>>l>>r;
        if(a==1) cout<<ps1[r]-ps1[l-1]<<endl;
        else cout<<ps2[r]-ps2[l-1]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}






void f(vector<int> v) {
    cout<<"Oi gente tudo bem?"<<endl;
}
