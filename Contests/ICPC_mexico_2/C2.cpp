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


int expbin(int base,int exp) {
    int res = 1;
    base%=MOD;
    while (exp>0){
        if (exp%2==1)res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}


void solve() {
    int q,n; cin>>q;
    int prob=1;
    while(q--){
        cin>>n;
        int nume=(6*((((n-1)*(n-1))/4)%MOD))%MOD;
        int deno=expbin(((n*(n-1))%MOD)*(n-2),MOD-2);
        prob=((prob*((nume*deno)%MOD))%MOD);
        cout<<prob<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}
