#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

void solve(){
    int i,n;cin>>n;
    vi v(n); for(auto &w :v) cin>>w;
    for(i=0;i<n;i++){
        if(v[i]%2==0) v[i]/=2;
        else v[i]+=(4-v[i]/2);
    }
    for(auto w :v)cout<<w<<" ";
    
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
