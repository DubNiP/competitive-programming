#include <bits/stdc++.h>

#define int long long

using namespace std;

#define MAX 10000098

void solve(){
    vector<int> f(MAX, -1);
    f[1] = 2;
    for (int i = 1; i < MAX; i++) {
        if (f[i] != -1) {
            continue;
        }
        f[i] = f[i-1] + 1;
        int j = f[i];
        int fj = i*3;
        while (j < MAX) {
            f[j] = fj;
            fj = j*3;
            j = f[j];
        }
    }
    int n; cin>>n;
    cout << f[n] << "\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

