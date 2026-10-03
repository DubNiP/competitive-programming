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

vvi adj;
vi val;
vi sz;

bool quadrado(int w){
    int aux=round(sqrt(w));
    if(aux*aux==w) return true;
    return false;
}

void dfs(int i,int p){
    sz[i]+=1;

    for(auto w : adj[i]){
        if(w!=p){
            dfs(w,i);
            sz[i]+=sz[w];
        }
    }
}

void solve() {
    int i,n; cin>>n;
    int resp=0;
    adj=vvi(n);
    val=vi(n);
    sz=vi(n);
    for(i=0;i<n;i++) cin>>val[i];

    for(i=0;i<n-1;i++){
        int a,b; cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
   

    for(i=0;i<n;i++){
        if(quadrado(val[i])){
            int s1=0,s2=0,s3=0;
            for(int w : adj[i]){
                int c=0;
                if(sz[w]>sz[i]) c=n-sz[i];
                else c=sz[w];
                s1+=c;
                s2+=c*c;
                s3+=c*c*c;
            }


            int p1=(s1*s1-s2)/2;
            int p2=(s1*s1*s1-3*s1*s2+2*s3)/6;
            resp+=p1+p2;
        }
    }
    cout<<resp<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
