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

void solve(){

    int n,i;
    cin>>n;
    vi v(n);
    for (auto&w : v) cin>>w;
    set<int>vis;
    vi resp;
    for (i=0;i<n;i++){
        int aux = i;
        int cont = 0;
        while (!vis.count(aux)) {
            vis.insert(aux);
            aux = v[aux] - 1;
            cont++;
        }
        if (cont != 0) resp.pb(cont);
    }
    int resp1 = 1, resp2 = 1;
    for (auto w : resp) resp1 = max(w, resp1);
    for (auto w : resp) resp2 = lcm(w, resp2);

    if (resp1 >= resp2) cout << resp1 << "\n";
    else {
        resp2 %= MOD;
        cout << resp2 << "\n";
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
