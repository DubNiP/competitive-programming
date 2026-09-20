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
    int i,n; cin>>n;
    int contimp=0,cont1=0,cont2=0;
    for(i=0;i<n;i++){
        int aux;cin>>aux;
        if(aux%2==1)contimp++;
        else if(aux%4==2) cont1++;
        else if(aux%4==0) cont2++;
    }
    int resp=max(cont1,cont2);
    resp=max(resp,contimp);
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
