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

pair<int, vector<pair<int,int>>> hungarian(int n, int m, const vvi& cost) {
    if (n == 0) return {0, {}};
    
    int N = max(n, m);
    vi u(N + 1), v(N + 1), p(N + 1), way(N + 1);
    
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vi minv(N + 1, INF);
        vector<bool> used(N + 1, false);

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            
            for (int j = 1; j <= N; ++j) {
                if (!used[j]) {
                    int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            
            for (int j = 0; j <= N; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    
    int total_cost = 0;
    vector<ii> matchings;
    
    for (int j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            total_cost += cost[p[j] - 1][j - 1];
            matchings.push_back({p[j] - 1, j - 1});
        }
    }
    
    return {total_cost, matchings};
}

vvi adj;

void solve(){

    int i,j,n,m1,m2; cin>>n>>m1>>m2;
    vector<ii> v1(m1),v2(m2);
    adj=vvi(m1,vi(m2,INF));
    for(auto &[a,b] : v1) cin>>a>>b;
    for(auto &[a,b] : v2) cin>>a>>b;

    if(m1!=m2){
        cout<<"-1"<<endl;
        return;
    }

    for(i=0;i<sz(v1);i++){
        for(j=0;j<sz(v2);j++){
            if((v1[i].f==v2[j].f&&v1[i].s==v2[j].s)||(v1[i].f==v2[j].s&&v1[i].s==v2[j].f)){
                adj[i][j]=0;
            }
            else if((v1[i].f!=v2[j].f&&v1[i].s!=v2[j].s)&&(v1[i].f!=v2[j].s&&v1[i].s!=v2[j].f)){
                adj[i][j]=2;
            }
            else adj[i][j]=1;
        }
    }

    cout<<hungarian(m1,m1,adj).f<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
