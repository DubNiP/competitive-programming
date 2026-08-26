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
using vii = vector<vector<pair<double,int>>>;

const int INF = 2e18;
const int MOD = 1e9+7;

struct Dijkstra{
    vector<double> dist;

    Dijkstra(int s,const vii & adj){
        dist.assign(adj.size(),INF);
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        dist[s]=0;
        pq.emplace(0,s);

        while(!pq.empty()){
            auto [d,u] = pq.top();pq.pop();
            if(d>dist[u]) continue;
            for(auto [w,v] : adj[u]){
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    pq.emplace(dist[v],v);
                }
            }
        }
    }
};

vii d;

void solve(){
    int n,h,i; cin>>n>>h;
    d=vii(2);
    vi raios(2,INF);
    vector<ii> cord(2);
    d[0].pb({(double)h,1});
    for(i=0;i<n;i++){
        vector<pair<double,int>> aux;
        d.pb(aux);
        int x,y,r; cin>>x>>y>>r;
        raios.pb(r);
        cord.pb({x,y});
        double auxi = h-y-r; if(auxi<0) auxi=0;
        d[sz(d)-1].pb({auxi,1});
        for(int j=0;j<sz(d)-1;j++){
            if(j==1)continue;
            if(j==0){
                double m=y-r; if(m<0)m=0;
                d[0].pb({m,sz(d)-1});
            }
            else{
                double diff=(double)sqrt((x-cord[j].f)*(x-cord[j].f)+(y-cord[j].s)*(y-cord[j].s))-(double)(r+raios[j]);
                if(diff<0)diff=0;
                d[j].pb({diff,sz(d)-1});
                d[sz(d)-1].pb({diff,j});
            }
        }
    }
    Dijkstra g(0,d);
    cout<<fixed<<setprecision(6)<<g.dist[1]<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
