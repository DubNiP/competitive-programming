#include <bits/stdc++.h>
#define f first
#define s second
#define push_back pb
using namespace std;
using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;



void solve(){
    int seq=0,n,i; cin>>n;
    
    for(i=0;i<n+1;i++){
        seq*=2;
        bool aux; cin>>aux;
        if(aux) seq++;
    }
    int resp=0;
    while(seq!=1){
        int auxi=seq*2;
        if(seq%2==1){
            seq^=auxi;
            seq--;
        }
        else seq/=2;
        resp++;
    }

    cout<<resp;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
