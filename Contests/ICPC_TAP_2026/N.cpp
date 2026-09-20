#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

const int MOD = 998244353;

struct mint {
  using m = mint;
  int val;
  mint(ll v = 0){
    ll x = v%MOD;
    if (x<0) x+=MOD;
    val = x;
  }
  m& operator+=(const m &o){
    ll x = (ll)val + o.val;
    if (x >= MOD) x -= MOD;
    val = x;
    return *this;
  }
  m& operator-=(const m &o){
    ll x = (ll)val-o.val;
    if (x < 0) x += MOD;
    val = x;
    return *this;
  }
  m& operator*=(const m &o){
    val = (1ll*val*o.val)%MOD;
    return *this;
  }
  m& operator/=(const m &o){
    val = (1ll*val*inv(o).val)%MOD;
    return *this;
  }
  friend m operator+(m a, const m &b) {return a+=b;}
  friend m operator-(m a, const m &b) {return a-=b;}
  friend m operator*(m a, const m &b) {return a*=b;}
  friend m operator/(m a, const m &b) {return a/=b;}
  static m power(m b, int e){
    m ans = 1;
    while(e>0){
      if (e&1) ans *= b;
      b*=b; e>>=1;
    }
    return ans;
  }
  static m inv(m n){ return power(n,MOD-2); }
};

void solve() {
    int n, k, a; cin >> n >> k >> a;

    if (n < 3) {
        cout << (k == 0 ? mint::power(mint(a), n).val : 0) << '\n';
        return;
    }

    int odd = (n+1)/2;
    int even = n/2;

    int max_k = (odd-1) + (even-1);
    if (k > max_k) {
        cout << "0\n"; return;
    }

    vector<mint> pa1(n+1, 1);
    for (int i = 1; i <= n; i++) {
        pa1[i] = pa1[i-1]*(a-1);
    }

    vector<mint> fat(n+1), ifat(n+1);
    fat[0] = 1;
    for (int i = 1; i <= n; i++) fat[i] = fat[i-1] * i;
    ifat[n] = mint::inv(fat[n]);
    for (int i = n; i >= 1; i--) ifat[i-1] = ifat[i] * i;

    auto choose = [&](int n, int r) -> mint {
        if (r < 0 || r > n) return 0;
        return fat[n] * ifat[r] * ifat[n-r];
    };

    mint ans = 0;
    for (int i = 0; i <= k; i++) {
        if (i <= odd-1 && k-i <= even-1) {
            ans += choose(odd-1, i)*a*pa1[odd-1-i] * choose(even-1, k-i)*a*pa1[even-1-k+i];
        }
    }

    cout << ans.val << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
