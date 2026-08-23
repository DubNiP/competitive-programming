vi sieve(int n) {
    vi prim;
    vi lp(n + 1, 0); 
    
    for (int i = 2; i <= n;i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }
        for (int p : primes) {
            if (p > lp[i] || i * p > n) break;
            lp[i * p] = p;
        }
    }
    return prim;
} 
