#include <bits/stdc++.h>
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


bool verify(string n,string m){

    int i,div=0;
    for(i=0;i<(int)m.size();i++){
        div*=2;
        if(m[i]=='1') div++;
    }

    int resto=0;
    for(i=0;i<(int)n.size();i++){
        resto*=2;
        resto%=div;
        if(n[i]=='1') resto++;
        resto%=div;
    }
    if(resto==0) return true;
    return false;
}


void solve(){

    int i,nz,mz;
    string n,m; cin>>n>>m;
    nz=n.size();mz=m.size();

    int bit=0;
    for(bit=0;bit<66000;bit++){
        int bitmask=bit;
        string nc=n,mc=m;
        for(i=0;i<nz;i++){
            if(nc[i]=='*'){
                bitmask%2==0 ? nc[i]='0' : nc[i]='1';
                bitmask/=2;
            }
        }
        for(i=0;i<mz;i++){
            if(mc[i]=='*'){
                bitmask%2==0 ? mc[i]='0' : mc[i]='1';
                bitmask/=2;
            }
        }
       
        if(verify(nc,mc)){
            cout<<nc<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
