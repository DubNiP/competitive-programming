#include <bits/stdc++.h>
using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long


void solve(){
    ll i,n;
    string s;
    cin>>n;
    cin>>s;
    vector<ll>ps(n+1);
    ll cont=0;
    ps[0]=0;
    for(i=1;i<n+1;i++){
        cont+=(ll)(s[i-1]-48);
        ps[i]=cont;
    }
    map<ll,ll>mapa;
    for(i=0;i<n+1;i++){
        mapa[ps[i]-i]++;
    }
    ll resp=0;
    for(auto w:mapa){
        resp+=(w.second*(w.second-1)/2);
    }
    cout<<resp<<endl;
}
 
int main() {
    _
    int t=1;
    cin>>t;
    while (t--) {
    solve();
    }
    return 0;
}
