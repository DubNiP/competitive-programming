#include <algorithm>
#include <iostream>
#include <vector>

#define int long long

using namespace std;

bool is_palindrome(vector<int>&& a) {
    int l = 0;
    int r = a.size() - 1;
    while (l < r) {
        if (a[l] != a[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

vector<int> to_base(int n, int b) {
    vector<int> ans;
    while (n > 0) {
        ans.push_back(n%b);
        n /= b;
    }
    return ans;
}

vector<int> get_divs(int n) {
    vector<int> ans;
    int d;
    for (d = 1; d*d < n; d++) {
        if (n%d == 0) {
            ans.push_back(d);
            ans.push_back(n/d);
        }
    }
    if (d*d == n) {
        ans.push_back(d);
    }
    return ans;
}


void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "*\n";
        return;
    }
    vector<int> ans;
    for (int i = 2; i*i <= n; i++) {
        if (is_palindrome(to_base(n, i))) {
            ans.push_back(i);
        }
    }
    for (int i : get_divs(n)) {
        if ((i-1)*(i-1) <= n) {
            continue;
        }
        if (is_palindrome(to_base(n, i - 1))) {
            ans.push_back(i - 1);
        }

    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int a : ans) {
        cout << a << " ";
    }
    cout << "\n";
}

signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

