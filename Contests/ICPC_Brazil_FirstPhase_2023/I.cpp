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

#define int ll



void solve(){
    
    int n; cin>>n;
    vector<int>ps(n+1);
    ps[0]=0;
    for(int i=1;i<=n;i++){
        int w; cin>>w;
        ps[i]=ps[i-1]+w;
    }
    int p=0,imp=0;
    for(auto w : ps) w%2==0 ? p++ : imp++;
    cout<<p*imp;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
