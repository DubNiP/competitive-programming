#include <bits/stdc++.h>
#define int ll
#define f first
#define s second
#define pb push_back 
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int,int>;
using vvi = vector<vector<int>>;


void solve() {
    int i,n; cin>>n;
    vi v(n);
    int soma=0;
    for(i=0;i<n;i++){
        cin>>v[i];
        soma+=v[i];
    }
    if(soma<=0){
        cout<<"-1\n";
        return;
    }

    vi pos;
    multiset<int>conj;
    for(i=0;i<n;i++){
        if(v[i]>0)pos.pb(v[i]);
        else conj.insert(v[i]);
    }
    sort(pos.begin(),pos.end());
    int num=pos[0];
    cout<<num<<" ";
    int ppos=1;
    for(i=1;i<n;i++){
        auto it=conj.lower_bound(1-num);
        if(it!=conj.end()){
            num+=*it;
            conj.erase(it);
        }
        else{
            num+=pos[ppos];
            ppos++;
        }
        cout<<num<<" ";
    }
    cout<<"\n";

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
    return 0;
}
