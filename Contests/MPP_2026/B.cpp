#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using ll = long long;
using vi = vector<int>;

using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int i,n,c,k,resp=0,ant,at; cin>>n>>c>>k;
    resp+=c+k;
    cin>>ant;
    for(i=1;i<n;i++){
        cin>>at;
        resp+=min(c+k,(at-ant)*c);
        ant=at;
    }
    cout<<resp;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
