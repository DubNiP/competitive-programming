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
    int i,u=0,d=0,z=0,uaux=0,n; cin>>n;
    vi v(n);
    vi valum(n,0),valzero(n,0);
    for(i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==1)u++;
        else d++;
    }
    string s; cin>>s;
    z=d;
    uaux=u;
    u=0;
    int pont=0;
    for(i=0;i<n;i++){
        if(v[i]==1){
            pont+=d;
            valum[i]=d;
            u++;
        }
        else{
            valzero[i]=u;
            d--;
        }
    }
    u=uaux;
    d=z;
    int zr=0,ur=0;
    cout<<pont<<" ";
    int ponteiro=0,r=n-1;
    for(auto w : s){
        if(w=='1'){
            while(ponteiro<n&&v[ponteiro]!=1) ponteiro++;
            if(ponteiro<n)pont-=max(0LL,valum[ponteiro]-zr);
            ur++;
            ponteiro++;
        }
        else{
            while(r>-1&&v[r]!=0) r--;
            if(r>-1)pont-=max(0LL,valzero[r]-ur);
            zr++;
            r--;
        }
        cout<<pont<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
