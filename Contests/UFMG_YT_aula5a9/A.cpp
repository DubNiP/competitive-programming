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

struct SegTree {
    struct Node{
        vi freq=vi(26,0);

        static Node combine(const Node &a,const Node &b){
            Node res;
            for(int i=0;i<26;i++){
                res.freq[i]=a.freq[i]+b.freq[i];
            }
            return res;
        }
        void apply(int v){
            freq[v-'a']++;
        }
    };

    int n;
    vector<Node> tree;

    SegTree(int size){
        n=size;
        tree.assign(2*n,Node());
    }

    void build (const string&a){
        for(int i=0;i<n;i++){
            tree[n+i].apply(a[i]);
        }
        for(int i=n-1;i>0;i--){
            tree[i]=Node::combine(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(int p,int value, int c){
        for(tree[p+=n].apply(value),p>>=1;p>0;p>>=1){
            tree[p]=Node::combine(tree[p<<1],tree[p<<1|1],c);
        }
    }

    Node query(int l,int r){
        Node resL,resR;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) resL=Node::combine(resL,tree[l++]);
            if(r&1) resR=Node::combine(tree[--r],resR);
        }
        return Node::combine(resL,resR);
    }
};


void solve(){
    int i,n,q; cin>>n>>q;
    string s; cin>>s;
    SegTree arv(n);
    arv.build(s);
    while(q--){
        int a,b,c; cin>>a>>b>>c;
        arv.update(a,b,c);
    }
    cout<<s<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
