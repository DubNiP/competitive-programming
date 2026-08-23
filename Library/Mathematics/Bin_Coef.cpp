struct Combinatorics {
    int max_n;
    vi fact, inv_fact;

    Combinatorics(int n) {
        max_n = n;
        fact.assign(max_n + 1, 1);
        inv_fact.assign(max_n + 1, 1);
        
        for (int i = 1; i <= max_n; i++) fact[i] = (fact[i - 1] * i) % MOD;
        
        inv_fact[max_n] = fexp(fact[max_n], MOD - 2);
        
        for (int i = max_n - 1; i >= 0; i--) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }

    int fexp(int base, int exp) {
        int res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    int nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }
    
    int nPr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv_fact[n - r] % MOD;
    }
};
