#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

void solve(){
    int i,n,q; cin>>n>>q;
    vvi ps(n+1,vi(n+1));
    for(i=0;i<=n;i++)ps[i][0]=0;
    for(i=0;i<=n;i++)ps[0][i]=0;

    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        char a; cin>>a;
        ps[i][j]=ps[i][j-1]+ps[i-1][j]-ps[i-1][j-1];
        if(a=='*') ps[i][j]++;
        }
    }
    while(q--){
        int y1,y2,x1,x2; cin>>y1>>x1>>y2>>x2;
        cout<<ps[y2][x2]-ps[y2][x1-1]-ps[y1-1][x2]+ps[y1-1][x1-1]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}

