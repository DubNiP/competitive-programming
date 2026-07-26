#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll i,j,n,m,cont=0,resp=0;
    cin>>n>>m;
    vector<ll>v(n);
    for(auto &w : v) cin>>w;
    vector<ll>esc(m);
    for(i=0;i<esc.size();i++){ 
        cin>>esc[i];
        esc[i]-=1;
    }
    
    sort(esc.begin(),esc.end());
    
    for(i=n-1;i>esc[m-1];i--)resp+=v[i];
    
    for(i=esc.size()-1;i>0;i--){
        for(j=esc[i];j>esc[i-1];j--){
            cont+=v[j];
        }
        resp+=abs(cont);
        cont=0;
    }

    for(i=esc[0];i>=0;i--) cont+=v[i];
    resp+=abs(cont);
    cout<<resp<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
