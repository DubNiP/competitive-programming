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
    int n,op; cin>>n>>op;
    int resp=op;
    int mult=0;
    op/=10;
    while(op>0){
        resp+=op;
        op/=10;
    }
    cout<<resp<<endl;


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
