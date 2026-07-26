#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;

ll expbin(ll resp,ll n){
    if(n==1) return 2;
    else if(n==0) return 1;
    if(n%2==0){
        ll aux=expbin(resp,n/2);
        return (aux*aux)%MOD;
    }
    else return (((resp*2)%MOD)*expbin(resp,n-1))%MOD;
}

void solve() {

    ll n; cin>>n;
    ll resp=1;
    resp=expbin(resp,n);
    cout<<resp;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    while(q--) solve();
    return 0;
}
