//TESTAR
int MITM(const vi& a, int S) {
    int n = sz(a);
    int half = n / 2;
    vi left, right;

    for (int mask = 0; mask < (1 << half); mask++) {
        int sum = 0;
        for (int i = 0; i < half; i++) 
            if (mask & (1 << i)) sum += a[i];
        left.pb(sum);
    }

    int rem = n - half;
    for (int mask = 0; mask < (1 << rem); mask++) {
        int sum = 0;
        for (int i = 0; i < rem; i++) 
            if (mask & (1 << i)) sum += a[half + i];
        right.pb(sum);
    }

    sort(all(right));

    int ans = 0;
    for (int x : left) {
        if (x > S) continue;
        auto it = upper_bound(all(right), S - x);
        if (it != right.begin()) {
            it--;
            ans = max(ans, x + *it);
        }
    }

    return ans;
}
