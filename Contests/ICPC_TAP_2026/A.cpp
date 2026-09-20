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
    int h, m, s; cin >> h >> m >> s;
    int sec = h*3600 + m*60 + s;
    int mid = 7200 + 30*60;
    if (sec == mid) cout << "=\n";
    else if (sec < mid) cout << "-\n";
    else cout << "+\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
