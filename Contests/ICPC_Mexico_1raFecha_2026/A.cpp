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
using ii = pair<int, int>;
using vvi = vector<vi>;

const int INF = 2e18;
const int MOD = 1e9+7;

void solve(){
    int i,n,m; cin>>n>>m;
    int cont1=0,cont2=0;
    for(i=0;i<n;i++) {
        int aux; cin>>aux; cont1+=aux;
    }
    for(i=0;i<m;i++){
        int aux; cin>>aux; cont2+=aux;
    }
    if(cont1+(cont1-1)/10+1>cont2) cout<<"NO\n";
    else cout<<"YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

