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

vi freq(1e6+10,0);

int calc(int w){
    int r=0;
    while(w>0){
        r+=w%10;
        w/=10;
    }
    return r;
}

void solve(){
    
    int i,n,k; cin>>n>>k;
    for(i=0;i<n;i++){
        int aux; cin>>aux; freq[aux]++;
    }
    
    int ind=1e6+8;
    int cont=0;
    int pol=0;
    while(cont<k&&ind>=0){
        if(freq[ind]>0){
            pol=calc(ind);
            cont+=freq[ind];
            freq[ind-pol]+=freq[ind];
            freq[ind]=0;
        }
        ind--;
    }
    if( ind<0) cout<<0;
    else cout<<pol;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
