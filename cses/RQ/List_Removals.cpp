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
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

const int inf=2e18;
const int MOD=1e9+7;

struct BIT {
    int n;
    vi tree;

    BIT(int n) : n(n) { tree.assign(n+1,0); for(int i=1;i<=n;i++) add(i,1); }

    void range_add(int l, int r, int val) {
        if (l > r) return;
        add(l, val);
        add(r + 1, -val);
    }

    void add(int i, int val){
        for(;i<=n;i+= i&-i) tree[i] +=val;
    }

    int query(int i) {
        int sum=0;
        for(;i>0;i-= i&-i) sum+=tree[i];
        return sum;
    }


    int query(int l,int r){
        if(l>r) return 0;
        return query(r) - query(l-1);
    }

    int bb(int aux){
      
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)/2;

            if(query(1,mid)<aux) l=mid+1;
            else{
                if(query(1,mid)==aux&&query(mid,mid)==1) return mid;
                r=mid-1;
            }
        }
        return 1;
    }
};

void solve() {
    int n; cin>>n;
    vi v(n); for(auto &w : v) cin>>w;
    
    BIT fen(n);

    for(int i=0;i<n;i++){
        int aux; cin>>aux;
        cout<<v[fen.bb(aux)-1]<<" ";
        fen.add(fen.bb(aux),-1);
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
