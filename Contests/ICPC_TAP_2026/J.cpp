#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back

#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

const int inf=2e18;
const int MOD=1e9+7;

vvi dp;

void verifica(string &s,int i,int j,int k){
    int t=0,a=0,p=0;
    if(i+j>sz(s)) return;
    for(int l=0;l<k;l++){
        if(s[i+l]=='T') t++;
        else if(s[i+l]=='A') a++;
        else p++;
    }
    for(int l=0;l<3-k;l++){
        if(s[i+j-l-1]=='T') t++;
        else if(s[i+j-l-1]=='A') a++;
        else p++;
    }
    if(a==t&&t==p&&dp[i+k][i+j-4+k]) dp[i][i+j-1]=1;
}

void solve() {

    string str; cin>>str;
    int i,j,k,n=sz(str);
    if(n%3!=0){
        cout<<"N"<<endl;
        return;
    }
    dp=vvi(n,vi(n,0));
    

    int t=0,a=0,p=0;
    for(i=0;i<n;i++){
        if(i>2){
            if(str[i-3]=='T') t--;
            else if(str[i-3]=='A') a--;
            else p--;
        }
        if(str[i]=='T') t++;
        else if(str[i]=='A') a++;
        else p++;
        if(t==a&&a==p) dp[i-2][i]=1;
    }
    
    for(j=6;j<=n;j+=3){
        for(i=0;i<=n-j;i++){
            for(k=i+2;k<i+j-1;k+= 3){
                    if(dp[i][k]==1&&dp[k+1][i+j-1]==1){
                        dp[i][i+j-1]=1;
                    }
            }
            for(k=0;k<4;k++){
                verifica(str,i,j,k);
            }
            for(k=i+2;k<i+j-2;k++){
                if(str[i]!=str[i+j-1]&&str[k]!=str[i]&&str[k]!=str[i+j-1]&&dp[i+1][k-1]==1&&dp[k+1][i+j-2]==1)
                    dp[i][i+j-1]=1;
            }
        }
    }
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(dp[i][j]==1) cout<<i<<j<<endl;
        }
    }*/
    if(dp[0][n-1]==1) cout<<"S"<<endl;
    else cout<<"N"<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
