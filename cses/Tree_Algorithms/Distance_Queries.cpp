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


vvi adj;
vvi lca;
vi in,out;
vi prof;

int tmp=0;
void dfs(int i,int ant,int r){
    prof[i]=r;
    in[i]=tmp++;
    for(auto w : adj[i]){
        if(w!=ant){
            lca[0][w]=i;
            dfs(w,i,r+1);
        }
    }

    out[i]=tmp++;
}

bool anc(int a,int b){
    if((in[a] <= in[b]) && (out[a] >= out[b])) return true;
    return false;
}


void bf(){
    dfs(0,-1,0);

    for(int k=1;k<30;k++)
        for(int i=0;i<(int)in.size();i++)
            lca[k][i]=lca[k-1][lca[k-1][i]];

}


void solve(){
    int n,q; cin>>n>>q;
    adj=vvi(n);
    in=vi(n);
    out=vi(n);
    prof=vi(n);
    lca=vvi(30,vi(n));

    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bf();

    while(q--){
        int a,b; cin>>a>>b; a--;b--;
        if(anc(a,b)||anc(b,a))cout<<abs(prof[a]-prof[b])<<endl;
        else{
            int aux=a;
            for(int k=29;k>=0;k--){
                if(!anc(lca[k][aux],b)) aux=lca[k][aux];
            }
            cout<<prof[a]-2*prof[lca[0][aux]]+prof[b]<<endl;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}

