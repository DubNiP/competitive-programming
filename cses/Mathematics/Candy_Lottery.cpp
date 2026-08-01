#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    ll n, k;
    cin >> n >> k;
    double resp = k;
    for (int i = 1; i < k; i++) {
        resp -= pow(((double)i / (double)k), (double)n);
    }
    cout << fixed << setprecision(6) << resp << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    //cin >> q;
    while (q--)  solve();
    return 0;
}
