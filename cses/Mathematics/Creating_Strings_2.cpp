#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
#define int long long
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


ll MOD=1e9+7;


vi fat(1e6+10),invfat(1e6+10);

int binexp(int w,int exp){
    if(exp==0) return 1;

    int aux = binexp(w,exp/2);
    if(exp%2==0) return (aux * aux)%MOD;
    return (((w * aux)%MOD)*aux)%MOD;
}

int invmod(int w){
    return binexp(w,MOD-2);
}

void calcfat(){
    fat[0]=1;
    for(int i=1;i<1e6+10;i++) fat[i]=(fat[i-1]*i)%MOD;
    invfat[1e6+9]=invmod(fat[1e6+9]);
    for(int i=1e6+8;i>=0;i--) invfat[i]=(invfat[i+1]*(i+1))%MOD;
}


void solve(){
    string s; cin>>s;
    int n=s.size();
    calcfat();
    vi freq(28,0);
    for(int i=0;i<n;i++) freq[s[i]-'a']++;
    int resp=fat[n];
    for(int i=0;i<27;i++){
        if(freq[i]>0) resp=(resp*invfat[freq[i]])%MOD;
    }
    cout<<resp;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
