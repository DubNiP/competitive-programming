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

vi freq(15,0);

void solve(){

    int n; cin>>n;
    int pj=0,pa=0;
    int i;
    
    for(i=0;i<4;i++){
        int aux; cin>>aux;
        freq[aux]++;
        aux=min(10,aux);
        i>1 ? pa+=aux : pj+=aux;
    }

    for(i=0;i<n;i++){
        int aux; cin>>aux;
        freq[aux]++;
        aux=min(10,aux);
        pj+=aux; pa+=aux;
    }

    for(i=1;i<14;i++){
        if(freq[i]==4) continue;
        int aux=min(10,i);
        if(pa+aux==23||(pj+aux>23&&pa+aux<=23)){
            cout<<i;
            return;
        }
    }
    cout<<"-1";

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
