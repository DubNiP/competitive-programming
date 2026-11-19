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

struct BIT {
    int n;
    vi tree;

    BIT(int n) : n(n) {
        tree.assign(n+1,0);
    }

    void add(int i, int val) {
        for(;i<=n;i+=i & -i)tree[i]+=val;
    }

    int query(int i){
        int sum=0;
        for(;i>0;i-=i&-i) sum+=tree[i];
        return sum;
    }

    int query(int l,int r){
        if(l>r) return 0;
        return query(r) - query(l-1);
    }
};
int d;
void solve(){
    int i,n; cin>>n>>d;
    
    vector<tuple<int,int,int>> v1(n); for(auto &[a,b,c] : v1) cin>>a>>b>>c;
    vector<tuple<int,int,int,int>> v2(n);

    
    sort(all(v1), [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        return get<0>(a) * get<1>(b) > get<1>(a) * get<0>(b);
    });

    for(i=0;i<n;i++){
        v2[i]=make_tuple(get<0>(v1[i]),get<1>(v1[i]),get<2>(v1[i]),0);
    }
    
    int cont=1;
    for(i=0;i<n;i++){
        get<2>(v1[i])=cont;
        cont++;
        get<3>(v2[i])=get<2>(v1[i]);
    }

    sort(all(v2), [](const auto& a, const auto& b) {
        return (d-get<0>(a)) * get<1>(b) > get<1>(a) * (d-get<0>(b));
    });

    BIT arv(n);
    int resp=0;
    for(i=0;i<n;i++){
        int id=get<3>(v2[i]);
        int w=get<2>(v2[i]);
        resp+=w*arv.query(id,n);
        arv.add(id,w);
    }
    cout<<resp<<endl;
    

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}
