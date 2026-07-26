#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;


void solve() {
    int n,m,i,j,q; cin>>n>>m;
    vi times(n); for(auto &w : times) cin>>w;
    vector<vi> platform(m,vi(n));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>platform[i][j];
        }
    }
    cin>>q;
    while(q--){
        int a,b,c; cin>>a>>b>>c; b--;c--;
        if((a+platform[b][c])%times[c]==0) cout<<platform[b][c]<<"\n";
        else cout<<(platform[b][c]+(times[c]-((a+platform[b][c])%times[c])))<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
