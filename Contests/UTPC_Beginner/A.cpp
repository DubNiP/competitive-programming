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

vector<string> v;

int analisa(int i,int j){
    if(v[i][j+1]=='#'||v[i][j-1]=='#') return 0;
    if(v[i-1][j]=='#'||v[i+1][j]=='#')return 0;
    return 1;
}

void solve() {
    int i,j,n,m; cin>>n>>m;
    int resp=0;
    v=vector<string>(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=1;i<n-1;i++){
        for(j=1;j<m-1;j++){
            if(v[i][j]=='.')resp+=analisa(i,j);
        }
    }
    cout<<resp<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}
