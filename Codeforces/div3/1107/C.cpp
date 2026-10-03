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
    string s; cin>>s;
    char c = s[0];
    bool ok=true;
    for(auto w : s){
        if(w!=c&&ok)ok=false;
        if(w==c&&!ok){
            cout<<"1"<<endl;
            return;
        }
    }
    if(ok)cout<<"1"<<endl;
    else cout<<"2"<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
