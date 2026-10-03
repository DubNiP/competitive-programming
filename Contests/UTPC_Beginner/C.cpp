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
    
    int i,n,m,k; cin>>n>>m>>k;
    int diff=0,xb=INF,xa=0,ya=0,yb=INF;
    vector<ii> v(n);
    for(i=0;i<n;i++){
        int x,y;cin>>v[i].f>>v[i].s;
        x=v[i].f;y=v[i].s;
        diff=max(diff,abs(x-y));
        if(x>xa)xa=x;
        if(x<xb)xb=x;
        if(y>ya)ya=y;
        if(y<yb)yb=y;
    }

    if(diff*k>m||(xa-xb)*k>m||(ya-yb)*k>m)cout<<"-1"<<endl;
    else{
        for(auto [a,b] : v){
            cout<<(a-xb)*k<<" "<<(b-yb)*k<<endl;
        }
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
