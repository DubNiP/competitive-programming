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
    int i,j,n; cin>>n;
    vvi mat(n,vi(n));
    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>mat[i][j];

    if(mat[0][0]>mat[0][1]&&mat[0][0]>mat[1][0]) cout<<"2\n";
    else if(mat[0][0]>mat[0][1]&&mat[0][0]<mat[1][0]) cout<<"1\n";
    else if(mat[0][0]<mat[1][0]&&mat[0][0]<mat[0][1]) cout<<"0\n";
    else cout<<"3\n";

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
