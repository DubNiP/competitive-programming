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
    
    int i,n; cin>>n;
    vi v;
    int aux; cin>>aux; v.pb(aux);
    for(i=1;i<n;i++) {
        cin>>aux;
        if(v[sz(v)-1]!=aux)v.pb(aux);
    }
    int m=sz(v);
    vi freq(2e5+10);
    set<int>ap;

    for(i=0;i<m;i++) ap.insert(v[i]);
    freq[v[0]]++;
    if(m==1){ cout<<0<<endl; return; }
    freq[v[m-1]]++;
    for(i=1;i<m-1;i++){
        if(v[i-1]==v[i+1]) freq[v[i]]++;
        freq[v[i]]++;
    }
    int resp=m-1;
    for(auto w : ap){
        resp=min(resp,m-1-freq[w]);
    }
    cout<<resp<<endl;



}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
