#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

vi v;
vi resp(1e6+10,0);
vb crivo(1e6+10,true);

int MOD=1e9+7;

//CÓDIGO INCOMPLETO



void crivocalc(){
    crivo[0]=crivo[1]=false;
    for(int i=2;i*i<1e6+5;i++){
        if(crivo[i]) for(int j=i*i;j<1e6+5;j+=i) crivo[j]=false;
    }
}

set<int> divide(int w){
    set<int> a;
    for(int i=2;i*i<=w;i++){
        if(!crivo[i]) continue;
        if(w%i==0){
            a.insert(i);
            if(crivo[w/i]) a.insert(w/i);
        }
    }
    if(crivo[w])a.insert(w);
    return a;
}


void compute(){

    for(int i=0;i<(int)v.size();i++){
       if(v[i]==1) continue;
       set<int> divisores;
       divisores=divide(v[i]);
       for(auto w : divisores) resp[w]++;
    }

}

int expbin(int b,int p){
    if(p==0) return 1;
    if(p==1) return b;
    int aux=expbin(b,p/2);
    if(p%2==0) return (aux*aux)%MOD;
    else return (b*(aux*aux)%MOD)%MOD;
}


void solve(){
    
    int n; cin>>n;
    v=vi(n); for(auto &w : v) cin>>w;

    crivocalc();
    compute();

    int q; cin>>q;
    while(q--){
        int num,pot=n; cin>>num;
        set<int>divisores = divide(num);
        for(auto w : divisores){
            pot-=resp[w];
        }
        if(divisores.size()>0) pot+=divisores.size()-1;

        cout<<expbin(2,pot)<<"\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
