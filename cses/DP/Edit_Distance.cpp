#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int i,j;
    string n,m; cin>>n>>m;
    int nsiz=n.size()+1,msiz=m.size()+1;

    vector<vector<int>>dp(nsiz,vector<int>(msiz));
    for(i=0;i<nsiz;i++) dp[i][0]=i;
    for(j=0;j<msiz;j++) dp[0][j]=j;


    for(i=1;i<nsiz;i++){
        for(j=1;j<msiz;j++){
            if(n[i-1]==m[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    cout<<dp[nsiz-1][msiz-1];

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
