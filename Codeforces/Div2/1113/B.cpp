#include <bits/stdc++.h>
#define int ll
#define f first
#define s second
#define pb push_back
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


void solve() {
    int n,m,i; cin>>n>>m;

    vi v1(n),v2(m);
    for(auto &w : v1) cin>>w; 
    for(auto &w : v2) cin>>w;
    if(n<2*m){
        cout<<"NO\n";
        return;
    }
    sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());

    vector<ii>pares(m);
    for(i=0;i<m;i++) pares[i].f=v1[i];
    int cont=1;
    for(i=n-1;i>n-1-m;i--){
        pares[m-cont].s=v1[i];
        cont++;
    }
    //for(auto [a,b] : pares) cout<<a<<" "<<b<<"\n";
    for(i=0;i<m;i++){
        if(v2[i]>pares[i].s||v2[i]<pares[i].f){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
