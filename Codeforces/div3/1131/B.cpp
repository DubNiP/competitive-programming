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

    int i,r, s,p; cin>>r>>s>>p;
    int sum=r+s+p;
    if(r>=s&&r>=p){
        for(i=0;i<sum;i++) cout<<"P";
    }
    else if(p>=r&&p>=s){
        for(i=0;i<sum;i++) cout<<"S";
    }
    else 
        for(i=0;i<sum;i++) cout<<"R";
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
