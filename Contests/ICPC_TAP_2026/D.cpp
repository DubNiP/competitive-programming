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
    string x; cin >> x;
    int n = x.size();
    
    vi y; y.reserve(x.size()+2); // y = 9x

    int carry = 0;
    for (int i = n-1; i >= 0; i--) {
        int d = x[i]-'0';
        int prod = 9*d + carry;
        y.push_back(prod%10);
        carry = prod / 10;
    }
    while (carry > 0) {
        y.push_back(carry%10);
        carry /= 10;
    }

    int lo = 0, hi = 1000000;
    int ans = hi;

    auto check = [&](int s) {
        int carry = s;
        int digit_sum = 0;
        
        for (int i = 0; i < (int)y.size(); i++) {
            int sum = y[i] + carry;
            digit_sum += sum%10;
            carry = sum/10;
        }
        while (carry > 0) {
            digit_sum += carry % 10;
            carry /= 10;
        }
        return digit_sum <= s;
    };

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid; hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
