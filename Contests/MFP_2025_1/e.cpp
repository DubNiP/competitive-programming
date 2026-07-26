#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vvi vector<vector<int>>


void solve() {
    int n,m,i,j;
    cin>>n>>m;
    vvi v(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) cin>>v[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if((i+j)%2!=v[i][j]%2) v[i][j]++;
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}

