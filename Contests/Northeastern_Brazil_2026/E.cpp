#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

void solve(){
    int n,i,t; cin>>n; t=n/3;
    int l=1,r=n;
    while(l!=r){
        int len=r-l+1;
        t=(len+2)/3;
        cout<<"? "<<t<<" ";
        for(i=l;i<=l+t-1;i++) cout<<i<<" ";
        for(i=l+t;i<=l+2*t-1;i++) cout<<i<<" ";
        cout<<endl;
        char c; cin>>c;
        if(c=='E') r=l+t-1;
        else if(c=='D'){
            r=l+2*t-1;
            l+=t;
        }
        else l+=2*t;
    }
    cout<<"! "<<l<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
