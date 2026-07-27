#include <bits/stdc++.h>
#define f first
#define s second
#define int ll
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;
using vvii = vector<vector<ii>>;

int INF=1e18;
vvii grafo;
vector<ii> dist;

void solve(){
    int n,m,i; cin>>n>>m;
    grafo=vvii(n);
    dist =vector<ii>(n,{INF,INF});
    for(i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        grafo[a].push_back({b,c});
    }
    
    priority_queue<pair<ii,bool>>fila;
    fila.push({{0,0},false});

    while(fila.size()!=0){
        int w=-(fila.top().f).f,v=(fila.top().f).s;
        bool used=fila.top().s;
        fila.pop();
            if(used==true&&dist[v].s>w){
            dist[v].s=w;
            for(auto [a,b] : grafo[v]){
                if(dist[v].s+b<dist[a].s){
                    fila.push({{-(dist[v].s+b),a},true});
                }
            }
        }
        if(used==false&&dist[v].f>w){
            dist[v].f=w;
            for(auto [a,b] : grafo[v]){
                if(dist[v].f+b<dist[a].f){
                   
                    fila.push({{-(dist[v].f+b),a},false});
                }
                if(dist[v].f+b/2<dist[a].s){
                  
                    fila.push({{-(dist[v].f+b/2),a},true});
                }
            }
        }
    }

    cout<<dist[n-1].s<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
