#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;


const int MOD = 1e9+7;

struct mint {
    int val;
    mint(ll v=0){
        ll x = v%MOD;
        if (x<0) x+=MOD;
        val = x;
    }
    mint& operator+=(const mint &o){
        ll x = (ll)val + o.val;
        if (x >= MOD) x -= MOD;
        val = x;
        return *this;
    }
    mint& operator-=(const mint &o){
        ll x = (ll)val - o.val;
        if (x < 0) x += MOD;
        val = x;
        return *this;
    }
    mint& operator*=(const mint &o){
        val = (1ll*val*o.val)%MOD;
        return *this;
    }
    mint& operator/=(const mint &o){
        val = (1ll*val*inv(o).val)%MOD;
        return *this;
    }
    friend mint operator+(mint a, const mint &b) {return a+=b;}
    friend mint operator-(mint a, const mint &b) {return a-=b;}
    friend mint operator*(mint a, const mint &b) {return a*=b;}
    friend mint operator/(mint a, const mint &b) {return a/=b;}
    static mint power(mint b, int e){
        mint ans = 1;
        while(e>0){
            if (e&1) ans *= b;
            b*=b; e>>=1;
        }
        return ans;
    }
    static mint inv(mint n){ return power(n,MOD-2); }
};

void solve(){
    int k; cin >> k;
    mint prob = 1;

    while(k--){
        int n; cin >> n;
        prob *= (6*mint(((n-1)*(n-1))/4))/(n*mint(n-1)*mint(n-2));
        cout << prob.val << '\n';;
    }

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
