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
    vector<int>freq(n+1);
    stack<int>p;
    string s; cin>>s;
    for(i=1;i<=sz(s);i++){
        if(s[i-1]=='1'){
            p.push(i);
        }
        else if(s[i-1]=='2'&&!p.empty()){
            int aux=p.top();
            p.pop();
            freq[aux]=true;
        }
        else{
            freq[i]=true;
        }
    }
    vi resp;
    for(i=1;i<=n;i++){
        if(freq[i]==false) resp.pb(i);
    }
    cout<<sz(resp)<<endl;
    for(auto w : resp) cout<<w<<" ";
    if(sz(resp)>0)cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
