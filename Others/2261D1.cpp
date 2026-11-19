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
    int i,n,m; cin>>n>>m;
    if(n==1){
        cout<<"0"<<endl;
        return;
    }
    if(n==2){
        cout<<"1"<<endl<<"1 1"<<endl;
        return;
    }
    cout<<(n+1)/2<<endl;

    for(i=0;i<(n+1)/2;i++){
        cout<<i+1<<" "<<i+(n+1)/2<<endl;
    }


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
