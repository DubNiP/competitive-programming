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

struct SparseTable {
    int n,K;
    vector<vector<ii>> st;

    inline ii f(ii l, ii r) { return max(l,r);}

    SparseTable(const vi &a){
        n=sz(a);
        K = __lg(n)+1;
        st.assign(K,vector<ii>(n));

        for(int i=0;i<n;i++) st[0][i]={a[i],i};

        for(int i=1;i<K;i++)
            for(int j=0;j+(1<<i)<=n;j++)
                st[i][j]=f(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }

    ii query(int r,int l){
        r--;l--;
        int k=__lg(r-l+1);
        return f(st[k][l],st[k][r-(1<<k)+1]);
    }
};


void solve(){

    int i,n,q;cin>>n>>q;
    vi v(n); for(auto &w : v)cin>>w;
    SparseTable t(v);
    while(q--){
        int l,r;cin>>l>>r;
        int ind =t.query(r,l).s+1;
        if(ind==l||ind==r||(r-l+1)%2==0) cout<<"Adilson"<<endl;
        else cout<<"Reginaldo"<<endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
