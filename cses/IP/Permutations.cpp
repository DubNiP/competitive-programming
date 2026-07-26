#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,i;
    cin>>n;
    if(n==2||n==3){
        cout<<"NO SOLUTION\n";
        return;
    }
    for(i=2;i<=n;i+=2) cout<<i<<" ";
    for(i=1;i<=n;i+=2) cout<<i<<" ";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
