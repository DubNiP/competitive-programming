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
    double a,b; cin>>a>>b;
    if(b>a)swap(a,b);
    if(a>b*3){
        cout<<fixed<<setprecision(10)<<a/sqrt(3);
        return;
    }
    cout<<fixed<<setprecision(10)<<(a*sqrt(3)/4)+(b*sqrt(3)/4);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
