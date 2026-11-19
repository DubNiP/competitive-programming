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

void solve() {

    int i,n,q; cin>>n>>q;

    vi v(n); for(auto &w : v) cin>>w;
    set<int> points;
    points.insert(0);
    points.insert(3);
    points.insert(6);
    points.insert(9);
    points.insert(12);
    points.insert(15);
    points.insert(5);
    points.insert(10);

    int r=0;
    for(i=0;i<n;i++){
        if(points.count(v[i])) r++;
    }
    cout<<r<<" ";

    while(q--){
        int a,b; cin>>a>>b;
        if(points.count(v[a-1])) r--;
        v[a-1]=b;
        if(points.count(v[a-1]))r++;
        cout<<r<<" ";
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
