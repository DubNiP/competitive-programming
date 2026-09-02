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

vi fat(1e6);

void calc_fat(){
    fat[0]=1;
    fat[1]=1;
    for(int i=2;i<1e6;i++) fat[i]=(fat[i-1]*i)%MOD;
}

int expbin(int w,int ex){
    if(ex==0) return 1;
    int aux=expbin(w,ex/2);
    if(ex%2==0) return (aux*aux)%MOD;
    else return (((aux*aux)%MOD)*w)%MOD;
}

int inv(int x){ return expbin(x,MOD-2);}

void solve(){

    int i,j,n,cont=0; cin>>n;
    vi v(n/2+1,0);
    vi p(n/2+1,0);
    for(i=1;i<n/2+1;i++) cin>>p[i];

    for(i=1;i<=n/2;i++){
        v[i]=p[i]/i;
        int pes=p[i];
        cont+=p[i];
        for(j=2*i;j<=n/2;j+=i) p[j]-=pes;
    }
    cont=n-cont;
    int resp;

    if(cont!=0) resp=(fat[n]*inv(cont))%MOD;
    else resp=fat[n];

    for(i=1;i<sz(v);i++){
        if(v[i]>0){
            resp=(resp*inv(expbin(i,v[i])))%MOD;
            resp=(resp*inv(fat[v[i]]))%MOD;
        }
    }
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_fat();
    solve();
    


    return 0;
}
