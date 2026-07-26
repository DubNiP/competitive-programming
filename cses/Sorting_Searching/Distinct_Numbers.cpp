#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    set<int>s;
    cin>>n;
    for(int i=0;i<n;i++){
        int aux; cin>>aux;
        s.insert(aux);
    }
    cout<<s.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
