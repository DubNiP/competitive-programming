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
using vvii = vector<vector<ii>>;


const int INF = 2e18;
const int MOD = 1e9+7;

vvii adj;
vi dist;
vi best_cut;
          

void solve(){

    int i,n,m; cin>>n>>m;
    adj=vvii(n);
    best_cut=vi(m,INF);
    for(i=0;i<m;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(make_pair(b,i+1));
        adj[b].pb(make_pair(a,i+1));
    }
    for(i=1;i<=m;i++){
        dist=vi(n,INF);
        deque<int>dq;
        dq.pb(0);
        dist[0]=0;
        while(sz(dq)>0){
            int v=dq[0];
            dq.pop_front();
            for(auto [a,b] : adj[v]){
                int c=0;
                if(b>=i) c=1;
                if(dist[a]>dist[v]+c){
                    dist[a]=dist[v]+c;
                    c ? dq.pb(a) : dq.push_front(a);
                }
            }
        }
        best_cut[i-1]=dist[n-1];
    }
    
    for (int k=1;k<=m;k++) {
        double mini=INF;

        for (int i=0;i<k;i++){
            double frac=(double)best_cut[i]/(double)(k-i);
            mini=min(mini, frac);
        }
        cout<<fixed<<setprecision(6)<<mini<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
