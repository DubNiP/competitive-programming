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

    int i,n,k; cin>>n>>k;
    if(k>n*2-1||k<n){
        cout<<"-1"<<endl;
        return;
    }
    vvi mat(n,vi(n,-1));
    mat[0][0]=1;

    int cont=2;
    while(k>n){
        mat[0][cont-1]=cont;
        k--;
        cont++;
    }
    for(i=1;i<n;i++){
        mat[i][i]=cont;
        cont++;
    }

    for(i=0;i<n;i++){
        for(auto &w : mat[i]){
            if(w==-1){
                w=cont;
                cont++;
            }
            cout<<w<<" ";
        }
        cout<<endl;
    }


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
