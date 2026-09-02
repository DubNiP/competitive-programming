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

int expbin(int w,int exp){
    if(exp==0) return 1;
    int aux=expbin(w,exp/2);
    if(exp%2==0) return (aux*aux)%MOD;
    return (((aux*aux)%MOD)*w)%MOD;
}

int inv(int x){ return expbin(x,MOD-2);}


void solve(){

    int i,n,q; cin>>n>>q;
    vi ps(q+1),v(q); ps[0]=0;
    int dois=2;
    for(i=1;i<=q;i++){
        int aux; cin>>aux;
        v[i-1]=aux;
        ps[i]=(ps[i-1]+(aux*inv(dois))%MOD)%MOD;
        dois*=2;
        dois%=MOD;
    }
    vi prob(n+1,0); prob[1]=1;
    vi lt(n+1,0);
    vi valesp(n+1,0);
    for(i=1;i<=q;i++){
        int num=v[i-1];
        valesp[num]=(valesp[num]+((((ps[i]-ps[lt[num]]+MOD)%MOD*expbin(2,lt[num]))%MOD)*prob[num])%MOD)%MOD;
        prob[num]=((prob[num]*inv(expbin(2,i-lt[num])))%MOD+inv(2))%MOD;
        lt[num]=i;
    }

    for(i=1;i<=n;i++) valesp[i]=(valesp[i]+((((ps[q]-ps[lt[i]]+MOD)%MOD*expbin(2,lt[i]))%MOD)*prob[i])%MOD)%MOD;
    for(i=1;i<sz(valesp);i++) cout<<valesp[i]<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
