#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,p=10;
    vector<ll>v;
    cin>>n;
    while(1+p<=n){
        if(n%(1+p)==0) v.push_back(n/(1+p));
        p*=10;
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(auto w : v) cout<<w<<" ";
    if(v.size())cout<<"\n";

}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int q = 1;
        cin >> q;
        while(q--) solve();
        return 0;
}

