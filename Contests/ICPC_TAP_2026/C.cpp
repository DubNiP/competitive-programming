#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vvi dp(n, vi(2));
    const int inf = 1e18;
    int nxta = -inf, nxtb = inf;

    for (int i = n-1; i >= 0; i--){
        dp[i][0] = max(min(b[i], nxtb), nxta);
        dp[i][1] = min(max(a[i], nxta), nxtb);

        nxta = max(nxta, dp[i][1]);
        nxtb = min(nxtb, dp[i][0]);
    }

    cout << max(min(0ll, nxtb), nxta) << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
