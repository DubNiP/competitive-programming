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
    int n, k; cin >> n >> k;
    if (k==1) cout << "S\n";
    else if (n==2 && (k&1)) cout << "S\n";
    else cout << "N\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
