//NAO TESTADO


void sos_dp_subsets(vi& dp, int m) {
    for (int i = 0; i < m; i++) 
        for (int mask = 0; mask < (1 << m); mask++) 
            if (mask & (1 << i)) dp[mask] += dp[mask ^ (1 << i)];
}

void sos_dp_supersets(vi& dp, int m) {
    for (int i = 0; i < m; i++)
        for (int mask = (1 << m) - 1; mask >= 0; mask--)
            if (!(mask & (1 << i))) dp[mask] += dp[mask ^ (1 << i)];
}
