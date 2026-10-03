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

int resp=0;

struct SegTree {
    struct Node {
        int freq=0;

        static Node combine(const Node &a,const Node &b){
            return{(a.freq+b.freq)%MOD};
        }
        void apply(int v){
            freq=(freq+v)%MOD;
        }
    };

    int n;
    vector<Node> tree;

    SegTree(int size){
        n=size;
        tree.assign(2*n,Node());
    }

    void build(const vi&a){
        for(int i=0;i<n;i++) tree[n+i].apply(a[i]);

        for(int i=n-1;i>0;i--)
            tree[i]=Node::combine(tree[i<<1],tree[i<<1|1]);
    }

    void update(int p, int value){
        for(tree[p+=n].apply(value),p>>=1;p>0;p>>=1)
            tree[p]=Node::combine(tree[p<<1],tree[p<<1|1]);
    }

    int query(int l,int r){
        Node resL,resR;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) resL = Node::combine(resL,tree[l++]);
            if(r&1) resR = Node::combine(tree[--r],resR);
        }
        return Node::combine(resL,resR).freq;
    }
};

void solve(){
    int i,n; cin>>n;
    vi v(n); for(auto &w : v) cin>>w;
    vi freq(1e5+10);
    SegTree arv(1e5+10);
    arv.build(freq);
    for(i=0;i<n;i++){
        int aux=arv.query(0,v[i]+1);
        aux++; resp=(resp+aux)%MOD;
        arv.update(v[i],aux);
    }
    cout<<resp;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
