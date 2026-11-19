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
const int MOD = 998244353;
const int tam = 50000;

vi fat(tam);
vi invfat(tam);

int expbin(int b,int e){
    if(e==0) return 1;
    if(e==1) return b;
    int aux=expbin(b,e/2);

    if(e&1) return (aux*((aux*b)%MOD))%MOD;
    return (aux*aux)%MOD;
}

int ferm(int b){ return expbin(b,MOD-2);}

// (n k)= n!/k!(n-k)!

int choose(int n,int k){
    if(k>n||k<0) return 0;
    return (((fat[n]*invfat[k])%MOD)*invfat[n-k])%MOD;
}

void solve(){
    int i,r,c,u,l; cin>>r>>c>>u>>l;
    r--;c--; swap(r,c);
        
    fat[0]=1;
    fat[1]=1;
    for(i=2;i<tam;i++) fat[i]=(fat[i-1]*i)%MOD;
    invfat[tam-1]=expbin(fat[tam-1],MOD-2);
    for(i=tam-2;i>=0;i--) invfat[i]=(invfat[i+1]*(i+1))%MOD;
    
    int totalx=choose(r+2*l,l);
    for(i=1;i<1010;i++){
        int add=(choose(2*l+r,l-i*(r+2))+choose(2*l+r,l+i*(r+2)))%MOD;
        int sub=(choose(2*l+r,l-1-(i-1)*(r+2))+choose(2*l+r,l-1+i*(r+2)))%MOD;
        totalx=(totalx-sub+MOD)%MOD;
        totalx=(totalx+add)%MOD;
    }
    int totaly=choose(c+2*u,u);
    for(i=1;i<1010;i++){
        int add=(choose(2*u+c,u-i*(c+2))+choose(2*u+c,u+i*(c+2)))%MOD;
        int sub=(choose(2*u+c,u-1-(i-1)*(c+2))+choose(2*u+c,u-1+i*(c+2)))%MOD;
        totaly=(totaly-sub+MOD)%MOD;
        totaly=(totaly+add)%MOD;
    }

    cout<<(((totalx*totaly)%MOD)*choose(r+2*l+c+2*u,r+2*l))%MOD<<endl;



}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
