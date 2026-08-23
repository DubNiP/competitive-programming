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

int query(int n,int k,bool ord){
    if(!ord&&n>=2*k) return k*2;
    if(ord&&n+1>=2*k) return k*2-1;
    if(n&1){
        if(ord) return query(n/2,k-(n+1)/2,!ord)*2;
        else return query((n+1)/2,k-n/2,!ord)*2-1;
    }
    else{
        if(ord) return query(n/2,k-(n+1)/2,ord)*2;
        else return query((n+1)/2,k-n/2,ord)*2-1;
    }
}

void solve(){
    int q; cin>>q;
    int n,k;
    while(q--){
        cin>>n>>k;
        cout<<query(n,k,0)<<endl;
    }



}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
