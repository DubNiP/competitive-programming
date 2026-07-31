#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
#define int ll
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

int MOD=1e9+7;
int pot = 31;

vi h,p;

void calc_pot(){
    p[0]=1;
    p[1]=pot;
    for(int i=2;i<p.size();i++){
        p[i]=(pot*p[i-1])%MOD;
    }
}

void calc_hash(string s,int n){
    h[0]=0;
    for(int i=1;i<=n;i++){
        h[i]=((h[i-1]*pot)%MOD+(s[i-1]-'a'+1)%MOD)%MOD;
    }
}

int get_hash(int l, int r){
    return ((h[r+1]-(h[l]*p[r-l+1]%MOD))+MOD)%MOD;
}

void solve(){

    string s; cin>>s;
    int i,n=s.size();
    h=vi(n+1);
    p=vi(n+1);
    calc_pot();
    calc_hash(s,n);
    for(i=1;i<n;i++){
        if(get_hash(0,n-i-1)==get_hash(i,n-1)){
            cout<<i<<" ";
        }
    }
    cout<<n;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
