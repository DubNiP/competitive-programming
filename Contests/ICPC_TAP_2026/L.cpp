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
    int n, m; cin >> n >> m;
    vi a(n);
    for (int &x : a) cin >> x;

    vi c = a;
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    
    for (int &x : a) x = lower_bound(all(c), x) - c.begin();

    m = c.size();

    vi qtd0(m+1);
    for (int i = n-1; i >= 0; i--){
        qtd0[a[i]] = max(qtd0[a[i]], qtd0[a[i]+1] + 1);
    }
    vi qtd1(m+1); // reverse
    for (int i = 0; i < n; i++){
        qtd1[a[i]] = max(qtd1[a[i]], qtd1[a[i]+1] + 1);
    }

    vvi dp(m+1, vi(2));
    // dp[i][0] -> min passadas pra pegar os itens a partir de i comecando agora pela esquerda
    // dp[i][1] -> min passadas pra pegar os itens a partir de i comecando agora pela direita

    dp[m][0] = dp[m][1] = 0;
    for (int i = m-1; i >= 0; i--){
        dp[i][0] = min(dp[i+qtd0[i]][1], dp[i+qtd0[i]][0]) + 1;
        dp[i][1] = min(dp[i+qtd1[i]][0], dp[i+qtd1[i]][1]) + 1;
    }

    cout << m << ' ' << min(dp[0][0], dp[0][1]) << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
