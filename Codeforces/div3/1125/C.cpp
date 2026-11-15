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

const int INF=2e18;
const int MOD=1e9+7;

void solve() {

    int i,n; cin>>n;
    vi v(n); for(auto &w : v) cin>>w;
    
    int vala1=INF,vala2=INF;
    map<int,int>freq;
    int resp=0;
    for(i=0;i<n-4;i+=2){
        int val=30000+v[i]+v[i+2]-v[i+4];
        resp+=freq[val];
        freq[val]++;
        if(vala1==val) resp--;
        if(vala2==val) resp--;
        vala2=vala1;
        vala1=val;
    }
    vala1=INF;vala2=INF;
    for(i=1;i<n-4;i+=2){
        int val=30000+v[i]+v[i+2]-v[i+4];
        resp+=freq[val];
        freq[val]++;
        if(vala1==val) resp--;
        if(vala2==val) resp--;
        vala2=vala1;
        vala1=val;
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
