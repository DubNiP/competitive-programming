#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,i;
    cin>>n;
   vector<pair<ll,pair<ll,ll>>>v(2*n);
    for(i=0;i<2*n;i++){
        ll a,b;
        cin>>a>>b;
        (v[i].second).first=a;
        (v[i].second).second=b;
        ll sum=a+b;
        v[i].first=sum;
    }
    ll r=0;
    sort(v.begin(),v.end());
    for(i=2*n-1;i>=n;i--) r+=(v[i].second).first;
    for(i=n-1;i>=0;i--) r-=(v[i].second).second;
    cout<<r;
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

