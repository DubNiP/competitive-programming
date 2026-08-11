#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    
    int n,i,j,k; cin>>n;
    vvi flight(n,vi(n));
    vector<vb>mark(n,vb(n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) cin>>flight[i][j];
    }
    int resp=0;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j||i==k||k==j) continue;
                if(flight[i][j]>flight[i][k]+flight[k][j]){
                    cout<<"-1\n";
                    return;
                }
                if(flight[i][j]==flight[i][k]+flight[k][j]&&!mark[i][j]){
                    resp++;
                    mark[i][j]=true;
                }
            }
        }
    }
    cout<<resp/2;


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
