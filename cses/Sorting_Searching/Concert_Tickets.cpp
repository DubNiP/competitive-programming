#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,m,i; cin>>n>>m;
    multiset<int> v;
    for(i=0;i<n;i++){
        int a; cin>>a;
        v.insert(a);
    }
    while(m--){
        int aux; cin>>aux;
        auto lw = v.upper_bound(aux);
        if(lw==v.begin()) cout<<"-1\n";
        else{
            cout<<(*(--lw))<<"\n";
            v.erase(lw);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
