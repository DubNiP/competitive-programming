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

void solve() {

    int i,n,k; cin>>n>>k;
    vector<ii> v;
    for(i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        if(a==b&&b==c) v.pb({a+b+c,inf});
        else if(a>b||b>c) v.pb({a+b+c,inf-1});
        else v.pb({a+b+c,min(b-a,c-b)});
    }
    int l=-inf,r=inf;
    int mov=k;
    int resp=-inf;
    while(l<=r){
        int mid=l+(r-l)/2;
        mov=k;
        for(auto [a,b] : v){
            if(mov<0) break;
            if(a<mid){
                if(b==inf) mov=-1;
                else if(b==inf-1) mov-=mid-a;
                else mov-=mid-a+2*b+2;
            }
        }
        if(mov<0) r=mid-1;
        else{
            resp=max(resp,mid);
            l=mid+1;
        }
    }
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
