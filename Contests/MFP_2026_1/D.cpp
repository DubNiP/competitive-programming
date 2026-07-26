#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,cont=0,numat=0;
    cin>>n;
    cin>>numat;
    cont+=numat;
    for(ll i=0;i<n-1;i++){
        ll aux;
        cin>>aux;
        numat=gcd(numat,aux);
        cont+=aux;
    }
    cout<<cont/numat;

 }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
    return 0;
}



