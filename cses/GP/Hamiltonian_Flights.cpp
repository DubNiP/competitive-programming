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

int n,m;
const int INF = 2e18;
const int MOD = 1e9+7;
vvi dp;

vvi adj;

int calc(int i, int conj){

    if(dp[i][conj]!=-1)return dp[i][conj];
    if(i==n-1){
        if(conj==((1LL<<n)-1)) return dp[i][conj]=1;
        return dp[i][conj]=0;
    }
    
    int resp=0;
    for( auto v : adj[i]){
        if(!((conj>>v)&1LL)){
            resp+=calc(v,conj|(1LL<<v));
            resp%=MOD;
        }
    }
    return dp[i][conj]=resp;
}

void solve(){
    int i; cin>>n>>m;
    adj=vvi(n);
    dp=vvi(n,vi(1LL<<n,-1));
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b;a--;b--;
        adj[a].pb(b);
    }
    
    cout<<calc(0,1)<<endl;
    

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
