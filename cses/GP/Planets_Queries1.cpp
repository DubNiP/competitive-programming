#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


const int INF = 2e18;
const int MOD = 1e9+7;

struct LCA{
    int log_n;
    vvi up;

    LCA(int n){
        log_n=__lg((int)1e9)+2;
        up.assign(log_n,vi(n,-1));
        for(int i=0;i<n;i++){
            int a; cin>>a; a--;
            up[0][i]=a;
        }
        for(int i=1;i<log_n;i++){
            dfs(i,n);
        }
    }
    void dfs(int u,int n){
        for(int i=0;i<n;i++) up[u][i]=up[u-1][up[u-1][i]];
    }
    int Verify(int n,int k){
        int cont=0;
        while(k>0){
            if(k%2==1) n=up[cont][n];
            k/=2;
            cont++;
        }
        return n;
    }
};

//Grafo transposto, ja que temos que ir pra frente em vez de voltar?
//Daí só fazer um Binary Lifting e acabou

void solve(){
    int i,n,q; cin>>n>>q;
   
    LCA g(n);

    while(q--){
        int a,b; cin>>a>>b; a--;
        cout<<g.Verify(a,b)+1<<endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
