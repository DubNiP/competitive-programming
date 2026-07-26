#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>>dp(1e6+10,vector<ll>(2);
vector<ll>resp(1e6+10);
ll MOD=1e9+7;

void process(){
    
}


void solve() {
    int n;
    cin>>n;
    cout<<resp[n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin>>q;
    dp[0][0]=1;
    dp[0][1]=1;
    process();
    while(q--) solve();
    return 0;
} 
