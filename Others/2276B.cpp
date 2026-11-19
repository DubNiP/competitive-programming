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
    string s; cin>>s;
    int n=sz(s);
    int resp=1;
    bool um=true,dois=true;
    for(int i=1;i<n-1;i++){
        if(s[i-1]==s[i+1]){
            if(um&&s[i]!=s[i-1]){
                um=false;
                resp++;
            }
            if(dois&&s[i]==s[i-1]){
                dois=false;
                resp++;
            }
        }
    }
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
