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
using ii = pair<int, int>;
using vvi = vector<vi>;

const int INF = 2e18;
const int MOD = 1e9+7;

vector<int> ans;
vector<int> crivo;
vector<bool> used;
int n, q;

vi sieve(int n){
    vb is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }

    vi primes;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            primes.pb(i);
        }
    }
    return primes;
}

/*
crivo: 2 3 5 7 11 
2 0
3 1
5 2
7 3
11 4
13 5
*/
bool calc(int cont,int ind){
    if(cont*crivo[ind]>n) return false;

    int x = cont*crivo[ind];
    ans.pb(x);

    for(int i=ind;i<sz(crivo);i++){
        if(!calc(x,i)) break;
    }
    return true;
}

void solve(){
    cin >> n >> q;

    crivo = sieve(n+1);
    used = vector<bool>(n+1, false);

    ans.pb(1);
    for(int i=0; i<sz(crivo); i++){
        calc(1, i);
    }

    for(int i=0; i<q; i++){
        int query; cin >> query;
        cout << ans[query-1] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

