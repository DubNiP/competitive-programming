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
    int n; cin>>n;
    vi v(n);
    int i,sum=0;
    for(i=0;i<n;i++){
        int aux; cin>> aux;
        v[i]=aux;
        sum+=aux;
    }
    if(sum==n) cout<<"-1"<<endl;
    else{
        for(i=1;i<n-1;i++){
            if(v[i]!=1){
                cout<<sum-1<<endl;
                return;
            }
        }
        cout<<v[0]+v[n-1]-1<<endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
