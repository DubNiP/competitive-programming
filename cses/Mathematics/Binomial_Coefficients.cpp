#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll MAX = 1000009;
ll MOD = 1000000007;
vector<ll>fat(MAX + 10), invfat(MAX + 10);
 
ll expbin(ll base) {
    ll resp = 1, exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) resp = (resp * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return resp;
}
 
 
void calc() {
    fat[0] = 1;
    int i;
    for (i = 1; i < MAX + 7; i++) {
        fat[i] = (i * fat[i - 1]) % MOD;
    }
    invfat[MAX] = expbin(fat[MAX]);
    for (i = MAX - 1; i >= 0; i--) {
        invfat[i] = (invfat[i + 1] * (i + 1)) % MOD;
    }
}
 
 
void solve() {
    int n, a, b, i;
    cin >> n;
    calc();
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        if (b == 0 || b == a) {
            cout << "1\n";
            continue;
        }
        ll aux = (fat[a] * invfat[a - b]) % MOD;
        aux = (aux * invfat[b]) % MOD;
        cout << aux << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while (q--)  solve();
    return 0;
}
