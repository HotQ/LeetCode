int numTrees(int n)
{
    if (n < 2) return 1;
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = 0;
        for (int j = 0; j <= i - 1; ++j) {
            temp += dp[j] * dp[i - 1 - j];
        }
        dp[i] = temp;
    }
    int res = dp[n];
    free(dp);
    return res;
}
