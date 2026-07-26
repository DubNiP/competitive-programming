#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,r=0;
    cin>>n;
    vector<int>v(n);
    for(auto &w : v) cin>>w;
    for(int i=1;i<n-1;i++){
        if(v[i]>v[i-1]&&v[i]>v[i+1]) r++;
    }
    cout<<r;
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}
