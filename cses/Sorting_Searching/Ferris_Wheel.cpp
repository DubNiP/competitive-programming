#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,x; cin>>n>>x;
    vector<int>v(n); for(auto &w : v) cin>>w;
    sort(v.begin(),v.end());

    int resp=0,pe=0,pd=n-1;
    while(pe<=pd){
        if(pe!=pd&&v[pd]+v[pe]<=x) pe++;
        pd--;
        resp++;
    }
    cout<<resp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
