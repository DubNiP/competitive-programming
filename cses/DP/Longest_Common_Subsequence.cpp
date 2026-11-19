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
    int n,m; cin>>n>>m;

    vi v(n); for(auto &w : v) cin>>w;
    vi b(m); for(auto &w : b) cin>>w;
    vvi memo(m+1,vi(n));
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(j!=0)memo[i][j]=memo[i-1][j-1];
            if(v[j]==b[i-1]) memo[i][j]++;
            if(j!=0)memo[i][j]=max(memo[i][j],memo[i][j-1]);
            memo[i][j]=max(memo[i][j],memo[i-1][j]);
        }
    }
    vi resp;
    int i=m,j=n-1;
    

    cout<<memo[i][j]<<endl;
    while(i>0&&j>=0){
        if(v[j]==b[i-1]){
            resp.pb(v[j]);
            i--;
            j--;
        }
        else if(j>0&&memo[i][j]==memo[i][j-1]) j--;
        else i--;
    }
    reverse(all(resp));
    for(auto w : resp) cout<<w<<" ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
