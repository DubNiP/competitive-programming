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

int tmp=0;
void dfs(int i,int ant){
    in[i]=tmp++;
    for(auto w : adj[i]){
        if(w!=ant){
            lca[0][w]=i;
            dfs(w,i);
        }
    }

    out[i]=tmp++;
}

bool anc(int a,int b){
    if((in[a] <= in[b]) && (out[a] >= out[b])) return true;
    return false;
}


void bf(){
    dfs(0,-1);

    for(int k=1;k<30;k++)
        for(int i=0;i<(int)in.size();i++)
            lca[k][i]=lca[k-1][lca[k-1][i]];

}


void solve(){
    int n,q; cin>>n>>q;
    adj=vvi(n);
    in=vi(n);
    out=vi(n);
    lca=vvi(30,vi(n));

    for(int i=1;i<n;i++){
        int a; cin>>a; a--;
        adj[a].pb(i);
        adj[i].pb(a);
    }
    bf();

    while(q--){
        int a,b; cin>>a>>b; a--;b--;
        if(anc(a,b))cout<<a+1<<endl;
        else if(anc(b,a))cout<<b+1<<endl;
        else{
            for(int k=29;k>=0;k--){
                if(!anc(lca[k][a],b)) a=lca[k][a];
            }
            cout<<lca[0][a]+1<<endl;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
