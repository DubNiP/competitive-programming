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

    int n; cin>>n;
    vi v(n); for(auto &w : v) cin>>w;
    int i,cont=0;
    string s; cin>>s;
    vi resp(n,1);

    for(i=0;i<n-1;i++){
        if(s[i]=='<') resp[i+1]=resp[i]+1;
        else if(s[i]=='=') resp[i+1]=resp[i];
    }
    for(i=n-2;i>=0;i--){
        if(s[i]=='>') resp[i]=max(resp[i+1]+1,resp[i]);
        else if(s[i]=='=') resp[i]=max(resp[i],resp[i+1]);
    }

    for(i=0;i<n;i++) cont+=resp[i]*v[i];
    cout<<cont<<endl;

    for(auto w : resp) cout<<w<<" ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
