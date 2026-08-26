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
    int n; cin>>n;
    vector<pair<char,char>>p(n);
    for(auto &w : p) cin>>w.f;
    for(auto &w : p) cin>>w.s;
    int g=0,r=0,difg=0,difr=0;
    for(int i=0;i<n;i++){
        if(p[i].f==p[i].s){
            if(p[i].f=='G')g++;
            else r++;
          
        }
        else if(p[i].f=='G')difg++;
        else difr++;
    }
    int resp=0;
    int med=abs(difg-difr);
    int m1=med/2;
    int m2=m1; if(med%2==1)m2++;
    resp-=m1*m1;
    resp-=m2*m2;
    resp+=g*g;
    resp+=r*r;
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
