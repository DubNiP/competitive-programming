#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;

struct SegTree {

    struct Node {
        //Caso queira mudar, mude a info aqui.
        int sum = 0;
        
        static Node combine(const Node& a, const Node& b) {
            return {a.sum + b.sum};
        }
        
        void apply(int v) {
            sum = v;
        }
    };

    int n;
    vector<Node> tree;

 
    SegTree(int size) {
        n = size;
        tree.assign(2 * n, Node());
    }

    void build(const vi& a) {
        for (int i = 0; i < n; i++) {
            tree[n + i].apply(a[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = Node::combine(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int p, int value) {
        for (tree[p += n].apply(value), p >>= 1; p > 0; p >>= 1) {
            tree[p] = Node::combine(tree[p << 1], tree[p << 1 | 1]);
        }
    }

    Node query(int l, int r) {
        Node resL, resR;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = Node::combine(resL, tree[l++]);
            if (r & 1) resR = Node::combine(tree[--r], resR);
        }
        return Node::combine(resL, resR);
    }
};





vvi adj;
vi val;
vi v;
vector<ii> pos;

void dfs(int i,int ant){
    pos[i].f=val.size();
    val.pb(v[i]);
    for(auto w : adj[i]) if(w!=ant) dfs(w,i);
    pos[i].s=val.size();
    val.pb(0);
}

void solve(){
    int i,n,q; cin>>n>>q;
    v=vi(n); for(auto &w : v) cin>>w;
    adj=vvi(n);
    pos=vector<ii>(n);

    for(i=0;i<n-1;i++){
        int a,b; cin>>a>>b; a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    SegTree tree((int)val.size());
    tree.build(val);

    while(q--){
        int a,b; cin>>a>>b;
        if(a==1){
            int c; cin>>c;
            tree.update(pos[b-1].f,c);
        }
        else cout<<tree.query(pos[b-1].f,pos[b-1].s).sum<<endl;
    }

    


}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
