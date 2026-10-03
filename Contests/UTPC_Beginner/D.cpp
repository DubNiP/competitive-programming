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

    int i=0,j,n,m; cin>>n>>m;
    int resp1=0,resp2=0;
    vi v(n);
    for(auto &w : v) cin>>w;
    int p=0;
    int mmc=v[0];

    while(i<n){
        mmc=1;
        for(j=p;j<=i;j++){
            mmc=lcm(mmc,v[j]);
        }
        if(mmc>m) p++;
        else{
            resp1+=(i-p+1);
            int x=i-p+1;
            resp2+=x*(x+1)/2;
            i++;
        }
    }
    cout<<resp1<<" "<<resp2<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
