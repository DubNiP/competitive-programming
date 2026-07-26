#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD= 1e9+7;

vector<vector<ll>>dp(1e6+10,vector<ll>(2));

void dpzada(){
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<1e6+8;i++){
        dp[i][0]=((4*dp[i-1][0])%MOD+(dp[i-1][1])%MOD)%MOD;
        dp[i][1]=((dp[i-1][0])%MOD+(2*dp[i-1][1])%MOD)%MOD;
    }
}


void solve() {
    int n;
    cin>>n;
    cout<<(dp[n-1][0]+dp[n-1][1])%MOD<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    dpzada();
    cin >> q;
    while(q--) solve();
    return 0;
}
