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

    vi v(n);
    vi p(n);
    for(int i=0;i<m;i++){
        int a; cin>>a; a--;
        if(v[a]==0){
            if(a==n-1){
                v[0]++;
                p[0]=a;
            }
            else{
                v[a+1]++;
                p[a+1]=a;
            }
        }
        else {
            v[p[a]]++;
            p[p[a]]=a;
        }
    }
    for(auto w : v) cout<<w<<" ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}
