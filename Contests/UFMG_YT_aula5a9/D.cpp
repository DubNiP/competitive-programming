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

vvi adj;
vi lim;
vb vis;
vi topo;
void top_sort(int i){
    vis[i]=true;
    for(auto w : adj[i]){
        if(!vis[w])top_sort(w);
    }
    topo.pb(i);
}

tuple<bool,int,int> dfs(int i){
    vis[i]=true;
    for(auto w : adj[i]){
        if(vis[w]){
            return make_tuple(false,-1,-1);
        }
        else{
            tuple<bool,int,int>x=dfs(w);
            if(get<0>(x)==false) return x;
            return make_tuple(true,get<1>(x),min(get<2>(x),lim[i]));
        }
    }
    return make_tuple(true,i,lim[i]);
}

void solve(){
    int i,n,m; cin>>n>>m;
    adj=vvi(n);
    lim=vi(n,INF);
    vis=vb(n);
    for(i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c; a--;b--;
        lim[b]=c;
        adj[a].pb(b);
    }
    for(i=0;i<n;i++){
        if(!vis[i])top_sort(i);
    }
    reverse(all(topo));
    vis=vb(n);
    vector<tuple<int,int,int>>resp;
    for(i=0;i<n;i++){
        if(!vis[topo[i]]&&sz(adj[topo[i]])>0){
            tuple<bool,int,int>aux=dfs(topo[i]);
            if(get<0>(aux)){
                resp.pb(make_tuple(topo[i],get<1>(aux),get<2>(aux)));
            }
        }
    }
    if(sz(resp)==0){
        cout<<"0"<<endl;
        return;
    }
    sort(all(resp));
    cout<<sz(resp)<<endl;
    for(auto [a,b,c] : resp){
        cout<<a+1<<" "<<b+1<<" "<<c<<endl;
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
