#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,maior=1,menor=10;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>maior)maior=v[i];
        if(v[i]<menor)menor=v[i];
    }
    cout<<maior-menor+1<<"\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while(q--) solve();
                        return 0;
}
