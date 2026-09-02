#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> cn(n+1), vn(n+1);
    for (int i = 1; i <= n; i++) {
        int ci, vi;
        cin >> ci >> vi;
        cn[i] = cn[i-1] + ci;
        vn[i] = vn[i-1] + vi;
    }
    int q;
    cin >> q;
    while (q--) {
        int j;
        cin >> j;
        int num = cn[j] - vn[j];
        if (num == 0) {
            cout << "NEUTRO\n";
        } else if (num < 0) {
            cout << "VENDA\n";
        } else {
            cout << "COMPRA\n";
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

