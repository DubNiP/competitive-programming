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
using vii = vector<ii>;

const int INF = 2e14;
const int MOD = 1e9+7;

vi t;
vii b1,b2;
vvi adj;
int mindist=INF,pdist=0;


void dfs1(int i,int p){
    for(auto w : adj[i]){
        if(w!=p){
            dfs1(w,i);
            if(b1[w].f+1<b1[i].f){
                b2[i]=b1[i];
                b1[i].f=b1[w].f+1;
                b1[i].s=b1[w].s;
            }
            else if(b1[w].f+1==b1[i].f) b1[i].s+=b1[w].s;
            else if(b1[w].f+1<b2[i].f){
                b2[i]=b1[w];
                b2[i].f++;
            }
            else if(b1[w].f+1==b2[i].f) b2[i].s+=b1[w].s;
        }
    }
}

void dfs2(int i, int p, ii to_p){
    if(b1[i].f>to_p.f){
        b2[i]=b1[i];
        b1[i].f=to_p.f;
        b1[i].s=to_p.s;
    }
    else if(b1[i].f==to_p.f) b1[i].s+=to_p.s;
    else if(to_p.f<b2[i].f) b2[i]=to_p;
    else if(to_p.f==b2[i].f) b2[i].s+=to_p.s;

    if(t[i]==1){
        if(b2[i].f<mindist){
            mindist=b2[i].f;
            pdist=b2[i].s;
        }
        else if(b2[i].f==mindist) pdist+=b2[i].s;
    }


    for(auto w : adj[i]){
        if(w!=p){
            if(b1[w].f+1==b1[i].f){
                if(b1[w].s!=b1[i].s) dfs2(w,i,{b1[i].f+1,b1[i].s-b1[w].s});
                else{
                    dfs2(w,i,{b2[i].f+1,b2[i].s});
                }
            }
            else dfs2(w,i,{b1[i].f+1,b1[i].s});
        }
    }
}

void solve(){

    int i,n; cin>>n;
    t=vi(n);
    b1=vii(n,{INF,0});
    b2=vii(n,{INF,0});


    for(i=0;i<n;i++) cin>>t[i];

    for(i=0;i<n;i++){
        if(t[i]) b1[i]={0,1};
    }
    adj=vvi(n);
  

    for(i=0;i<n-1;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs1(0,-1);
    dfs2(0,-1,{INF,0});
    cout<<mindist<<" "<<pdist/2;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
