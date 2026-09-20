#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back

#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

const int inf = 2e18;
const int MOD = 1e9+7;

void solve() {
    int a,b;cin>>a>>b;
     if(b==0){
        cout<<a<<" "<<0<<endl;
        return;
    }
    
    int resp=a^b;
    int mov=0;
    
    int ata = a;
    int atb = b;
    int ope = 0;
    
    int ab = b;
    if(ab==0)ab=1;
    else {
        int p=1;
        while (p<=b)p*=2;
        ab=p;
    }
    int diff=ab-b;
    if (ata>=diff){
        ata-=diff;
        atb+=diff;
        ope+=diff;
        if((ata^atb)>resp){
            resp=ata^atb;
            mov=ope;
        }
    }
    
    while (ata>=atb&&atb>0){
        ope+=atb;
        ata-=atb;
        atb*=2;
        if((ata^atb)>resp){
            resp=ata^atb;
            mov=ope;
        }
    }
    cout<<resp<<" "<<mov<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin>>q;
    while (q--) solve();
    return 0;
}
