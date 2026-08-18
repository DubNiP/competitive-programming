//TESTAR
int knapsack(const vi& weights, const vi& values, int W) {
    int n = sz(weights);
    vi dp(W + 1, 0);

    for (int i = 0; i < n; i++)
        for (int w = W; w >= weights[i]; w--)
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
    
    return dp[W];
}
