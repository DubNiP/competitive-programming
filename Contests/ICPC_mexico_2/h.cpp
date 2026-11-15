#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct segtree{
    struct node{
        int mx = 0;
        static node combine(const node& a, const node&b){
            return {max(a.mx, b.mx)};
        }
        void apply(int v){
            mx = v;
        }
    };
    int n;
    vector<node> t;
    void init(int n_){
        n = n_;
        t.assign(2*n, node());
    }
    void set(int p, int v){
        for(t[p+=n].apply(v), p >>=1; p > 0; p >>= 1){
            t[p] = node::combine(t[p<<1], t[p<<1|1]);
        }
    }
    node query(int l, int r){
        node resL, resR;
        for(l +=n, r+=n; l<r; l>>=1, r>>=1){
            if(l&1) resL = node::combine(resL, t[l++]);
            if(r&1) resR = node::combine(t[--r], resR);
        }
        return node::combine(resL, resR);
    }
};

void solve(){
    int n; cin >> n;
    vi r(n), k(n);
    for(int i = 0; i < n; i++) cin >> r[i];
    for(int i = 0; i < n; i++) cin >> k[i];
    int t = 0;
    segtree s;
    s.init(1e5+1);
    for(int i = 0; i < n; i++){
       int preT = s.query(0, r[i]+1).mx; 
       if(preT > t) s.set(r[i], preT + r[i]+k[i]), t = preT + 1;
       else s.set(r[i], r[i]+k[i]+t), t += 1; 
    }
    cout << s.query(0, 1e5+1).mx << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

