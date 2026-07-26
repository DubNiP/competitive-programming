#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,i;
    cin>>n;
    vector<int>v(n);
    for(auto &w : v) cin>>w;

    vector<int>LIS;
    for(i=0;i<n;i++){
        auto low = lower_bound(LIS.begin(),LIS.end(),v[i]);
        if(low==LIS.end()) LIS.push_back(v[i]);
        else LIS[low-LIS.begin()]=v[i];
    }
    cout<<LIS.size();
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

