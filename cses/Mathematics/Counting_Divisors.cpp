#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void imprime(int x) {
    int resp=0;
    for (int i = 1; i < sqrt(x); i++) {
        if (x % i == 0) {
            resp += 2;
        }
    }
    if (sqrt(x) == (int)sqrt(x)) resp++;
    cout << resp << "\n";
}
 
void solve() {
    int x;
    cin >> x;
    imprime(x);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int q = 1;
    cin >> q;
    while (q--)  solve();
    return 0;
}
