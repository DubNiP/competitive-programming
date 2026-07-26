#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(auto &w : v) cin>>w;
    sort(v.begin(),v.end());
    int pointer=0;
    for(int i=1;i<=m;i++){
        while(v[pointer]<i&&pointer<n) pointer++;
        cout<<n-pointer<<" ";
    }
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}

