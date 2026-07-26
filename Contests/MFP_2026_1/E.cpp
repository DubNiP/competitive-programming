#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int INF=1e8;

vector<vector<ll>>dp(2001,vector<ll>(7,INF));

void solve() {
    ll i,j,k,vol,pit,s;
    ll t1,t2,t3;
    ll d1,d2,d3;
    cin>>vol>>pit>>s;
    cin>>t1>>t2>>t3;
    cin>>d1>>d2>>d3;
    dp[0][s+1]=0;

    for(i=0;i<=vol;i++){
        for(j=1;j<=s+1;j++){
           for(k=0;k<=d3;k++){
               if(i-k>=0&&dp[i-k][j]!=INF&&k<=d1) dp[i][j-1]=min(dp[i][j-1],dp[i-k][j]+t1*k+pit);
               else if(i-k>=0&&dp[i-k][j]!=INF&&k<=d2) dp[i][j-1]=min(dp[i][j-1],dp[i-k][j]+t2*k+pit);
               else if(i-k>=0&&dp[i-k][j]!=INF) dp[i][j-1]=min(dp[i][j-1],dp[i-k][j]+t3*k+pit);
           }
        } 
    }
    ll resp=INF;
    for(i=vol;i<2001;i++){
        for(j=0;j<6;j++){
            resp=min(resp,dp[i][j]);
        }
    }
    cout<<resp-pit;
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
} 
