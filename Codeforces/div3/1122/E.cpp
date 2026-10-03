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
vi prim;
vi lp;
vi mp;

void sieve(){
    lp=vi(2*1e5+11,0);
    mp=lp;
    for (int i=2;i<=2*1e5+10;i++){
        if(lp[i]==0){
            lp[i]=i;
            mp[i]=i;
            prim.pb(i);
        }
        for(int p : prim){
            if(p>lp[i]||i*p>2*1e5+10)break;
            lp[i*p]=p;
            mp[i*p]=mp[i];
        }
    }
}

void solve() {
    int n,k,i; cin>>n>>k;
    int resp=0;
    vi v(n);
    vi op(n+1,inf);
    int maxi=0;
    for(i=0;i<n;i++){
        cin>>v[i];
        maxi=max(v[i],maxi);
    }
    
    for(i=0;i<=maxi;i++){
        if(i<=k){
            op[i]=0;
            continue;
        }
        int aux=i;
        while(aux>1){
            op[i]=min(op[i],1+lp[aux]*op[i/lp[aux]]);
            int x=lp[aux];
            while(aux%x==0) aux/=x;
        }
    }
    for(i=0;i<n;i++) resp+=op[v[i]];
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    sieve();
    while(q--) solve();
    return 0;
}
