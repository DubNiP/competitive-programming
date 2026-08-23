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

struct SegTree{
    struct Node{
        int maxi=0;
        static Node combine(const Node&a,const Node&b){
            return {max(a.maxi,b.maxi)};
        }
        void apply(int v){
            maxi-=v;
        }
    };
    int n;
    vector<Node> tree;
    SegTree(int size){
        n=1;
        while(n<size) n*=2;
        tree.assign(2*n,Node());
    }
    void build(const vi &a){
        for(int i=0;i<sz(a);i++)
            tree[n+i].maxi=a[i];
        for(int i=n-1;i>0;i--)
            tree[i]=Node::combine(tree[i<<1],tree[i<<1 | 1]);
    }
    void update(int p,int value){
        for(tree[p+=n].apply(value),p>>=1;p>0;p>>=1)
            tree[p]=Node::combine(tree[p<<1],tree[p<<1|1]);
    }
    int query(int v){
        if(tree[1].maxi<v) return -1;
        int p=1;
        while(p<n){
            if(tree[p<<1].maxi>=v){
                p<<=1;
            }
            else p=(p<<1) | 1;
        }
        return p-n;
    }
};

void solve(){
    int n,m; cin>>n>>m;
    vi v(n); for(auto &w : v) cin>>w;
    SegTree t(n);
    t.build(v);
    vi resp;
    while(m--){
        int p; cin>>p;
        int ind=t.query(p);
        resp.pb(ind+1);
        if(ind!=-1)t.update(ind,p);
    }
    for(auto w : resp) cout<<w<<" ";

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
