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
using ii = pair<int, int>;
using vvi = vector<vi>;

const int INF = 2e18;
const int MOD = 1e9+7;
vi resp(1e6+5,0);

void calc(){
    resp[3]=1;
    int imp=2,p=1;
    for(int i=4;i<1e6+4;i++){
    resp[i]+=resp[i-1];
        if(i%2==0){
            resp[i]=(resp[i]+((p-1)*p/2)%MOD)%MOD;
            resp[i]=(resp[i]+((imp-1)*imp/2)%MOD)%MOD;
            p++;
        }
        else{
            resp[i]=(resp[i]+(p*imp)%MOD)%MOD;
            imp++;
        }
    }
}

void solve(){

    int q; cin>>q;
    while(q--){
        int n; cin>>n; cout<<resp[n]<<"\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    calc();
    solve();
    return 0;
}

