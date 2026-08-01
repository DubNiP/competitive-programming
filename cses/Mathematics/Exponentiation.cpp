#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = (1e9) + 7;
 
 
ll binexp(ll a, ll b) {
    if (b == 1) return a;
    if (b == 0)return 1;
    ll res = binexp(a, b / 2) % MOD;
    if (b % 2 == 0) return (res * res) % MOD;
    return ((a * res) % MOD * res) % MOD;
 
}
 
 
void solve() {
    ll a, b;
    cin >> a >> b;
    cout << binexp(a, b) % MOD << "\n";
 
}
 
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while (q--)  solve();
    return 0;
}
