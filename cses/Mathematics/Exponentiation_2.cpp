#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD1 = (1e9) + 7;
ll MOD2 = (1e9) + 6;
 
 
ll binexp(ll a, ll b, ll MOD) {
    if (b == 1) return a;
    if (b == 0)return 1;
    ll res = binexp(a, b / 2, MOD) % MOD;
    if (b % 2 == 0) return (res * res) % MOD;
    return ((a * res) % MOD * res) % MOD;
 
}
 
 
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = binexp(b, c, MOD2);
    ll e = binexp(a, d, MOD1);
    cout << e << "\n";
 
 
}
 
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while (q--)  solve();
    return 0;
}

