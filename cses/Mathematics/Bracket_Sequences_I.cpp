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

vi fat,invfat;

int expbin(int b, int e){
    if(e==0) return 1;
    if(e==1) return b;
    int aux=expbin(b,e/2);
    if(e%2==0) return (aux*aux)%MOD;
    return (((aux*aux)%MOD)*b)%MOD;
}

int ferm(int b){
    return expbin(b,MOD-2);
}

int comb(int x,int y){
    return (((fat[x]*invfat[y])%MOD)*invfat[x-y])%MOD;
}


void solve(){
    int i,n; cin>>n;
    if(n&1){
        cout<<"0"<<endl;
        return;
    }
    fat=vi(2*n+10);
    invfat=fat;

    fat[0]=1;
    fat[1]=1;
    for(i=2;i<=2*n+5;i++) fat[i]=(fat[i-1]*i)%MOD;
    invfat[2*n+5]=ferm(fat[2*n+5]);
    for(i=2*n+4;i>=0;i--) invfat[i]=(invfat[i+1]*(i+1))%MOD;

    cout<<(comb(n,n/2)*ferm(n/2+1))%MOD;

    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
