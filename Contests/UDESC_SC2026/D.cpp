#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,maxi=0;
    cin>>n;
    vector<ll>v(n);
    for(auto &w : v) cin>>w;
    vector<ll>next;
    while(v.size()>1){
        for(int i=0;i<v.size();i+=2){
            if(i+1>=v.size()) next.push_back(v[i]);
            else {
                maxi=max(maxi,abs(v[i]-v[i+1]));
                next.push_back(max(v[i],v[i+1]));
            }
        }
        swap(v,next);
        next.clear();
    }
    cout<<maxi;
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

