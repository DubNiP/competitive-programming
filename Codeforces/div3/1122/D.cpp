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

const int inf=2e18;
const int MOD=1e9+7;

void solve() {
    int i,cont,resp,n; cin>>n;
    set<int> v;
    for(i=0;i<n;i++){
        int aux;
        cin>>aux;
        v.insert(aux-i);
    }
    int ant=inf;
    cont=0;
    resp=0;
    for(auto w : v){
        if(w==ant+1){
            ant=w;
            cont++;
            resp=max(resp,cont);
        }
        else{
            ant=w;
            cont=0;
        }
    }
    cout<<resp+1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
