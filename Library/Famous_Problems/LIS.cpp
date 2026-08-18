//TESTAR
int lis(const vi& a) {
    vi dp;
    for (int x : a) {
        auto it = lower_bound(all(dp), x);
        if (it == dp.end()) dp.pb(x);
        else *it = x;
    }
    return sz(dp);
}
