#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        n%2==0 ? n/=2 : n=n*3+1;
    }
    cout<<n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
