#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int m,n,i,j;
    cin>>m>>n;
    vector<vector<char>>v(m,vector<char>(n));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    ll resp=0;
    vector<vector<vector<int>>>freq(m,vector<vector<int>>(n,vector<int>(2,0)));
    for(i=0;i<m;i++){
        for(j=n-1;j>=0;j--){
            resp+=freq[i][j][0]*freq[i][j][1];
            if(i<m-1&&v[i+1][j]==v[i][j]) freq[i+1][j][0]+=freq[i][j][0]+1;
            if(j>0&&v[i][j-1]==v[i][j]) freq[i][j-1][1]+=freq[i][j][1]+1;
        }
    }
    cout<<resp;
}

int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
            int q = 1;
                    while(q--) solve();
                        return 0;
}
