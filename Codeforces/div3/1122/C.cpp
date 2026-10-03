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
    string s; cin>>s;
    int u=0,z=0;
    for(i=0;i<n;i++){
        if(s[i]=='1')u++;
        else z++;
    }
    int resp=inf;
    int cont=0;
    if(s[0]=='1'){
        cout<<z<<endl;
        return;
    }
    z--;
    for(i=1;i<n;i++){
        if(s[i]=='1'){
            resp=min(resp,z+cont);
            cont++;
        }
        else{
            z--;
            resp=min(resp,z+cont);
        }
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
