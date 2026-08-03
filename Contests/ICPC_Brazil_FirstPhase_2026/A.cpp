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
    int m,n,i,j,resp=0; cin>>m>>n;
    vvi v(m,vi(n));
    for(i=0;i<m;i++) for(j=0;j<n;j++) cin>>v[i][j];
    for(i=0;i<n;i++){
        int aux=0;
        for(j=0;j<m;j++){
            aux=max(aux,v[j][i]);
        }
        resp+=aux;
    }
    cout<<resp;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
