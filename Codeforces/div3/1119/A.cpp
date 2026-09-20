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
    int n,i,k; cin>>n>>k;
    string s; cin>>s;
    int cont=0;
    bool paga=true;
    for(i=0;i<sz(s);i++){
        if(s[i]=='0') paga=false;
        if((i+1)%k==0){
            if(paga) cont++;
            paga=true;
        }
    }
    cout<<cont<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
