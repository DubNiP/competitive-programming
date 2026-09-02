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
using ii = pair<int, int>;
using vvi = vector<vector<int>>;

const int INF = 2e18;
const int MOD = 1e9+7ll;

int n, m;
vector<vector<char>> mp, cp_init;

void printg(vector<vector<char>>& graph){
    int nx, mx;
    nx = sz(graph);
    mx = sz(graph[0]);

    cout << "print:\n";
    for(int i=0; i<nx; i++){
        for(int j=0; j<mx; j++){
            cerr << graph[i][j];
        }
        cerr << "\n";
    }
    cerr << "\n";
}

int rotate(vector<vector<char>>& cp){
    int qt = 0;
    // cp = mp; // m*n
    // pq qnd quando n > m da runtime?
    vector<vector<char>> mp_aux = cp;

    // printg(cp);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cp[n-1-i][m-1-j] = mp_aux[i][j];
        }
    }
    // cerr << "vertical: ";
    // printg(cp);

    if(cp == mp)
        qt++;

    if(n != m)
        return qt;

    // right
    // cerr << "right: ";
    // printg(cp);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cp[j][m-1-i] = mp_aux[i][j];
        }
    }
    if(cp == mp)
        qt++;

    // left
    // cerr << "left: ";
    // printg(cp);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cp[n-1-j][i] = mp_aux[i][j];
        }
    }
    if(cp == mp)
        qt++;

    return qt;
}

int window(vector<vector<char>>& cp){
    int qt = 0;
    cp = mp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cp[i][m-1-j] = mp[i][j];
        }
    }

    if(cp == mp)
        qt++;

    qt += rotate(cp);

    return qt;
}

void solve(){
    cin >> n >> m;

    mp = vector<vector<char>>(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mp[i][j];
        }
    }

    int ans = 1;
    cp_init = mp;
    ans += rotate(cp_init);
    cp_init = mp;
    ans += window(cp_init);
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

