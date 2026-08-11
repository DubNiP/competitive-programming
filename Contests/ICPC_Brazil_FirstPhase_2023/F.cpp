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
    int d,c,r; cin>>d>>c>>r;
    vi v(c); for(auto &w : v) cin>>w;
    for(int i=0;i<r;i++){
        int aux; cin>>aux;
        d+=aux;
    }
    int resp=r;
    for(int i=0;i<c;i++){
        d-=v[i];
        if(d<0) break;
        resp++;
    }
    cout<<resp;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
