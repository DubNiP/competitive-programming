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
    vi v(n);
    int cz=0;
    for(i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==0) cz++;
    }
    if(cz==1) cout<<"NO\n";
    else if(cz==0){
        cout<<"YES\n";
        string s="";
        for(i=0;i<n;i++) s+="A";
        cout<<s<<endl;
    }
    else{
        cout<<"YES\n";
        bool ok=false;
        for(i=0;i<n;i++){
            if(v[i]==0){
                if(ok)cout<<"A";
                else{
                    ok=true;
                    cout<<"B";
                }
            }
            else cout<<"C";
        }
        cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
