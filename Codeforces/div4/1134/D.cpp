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
    int i,n; string s; cin>>n>>s;

    vb v(26,false);

    for(i=0;i<n;i++){
        char p=s[i],q=s[n-1-i];
        if(p>q) swap(p,q);
        while(p!=q){
            v[q-'a']=true;
            q--;
        }
    }
    int resp=0;
    for(auto w : v){
        if(w) resp++;
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
