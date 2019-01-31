int climbStairs(int n){
    if (n == 1) return 1;
    if (n == 2) return 2;
    int p = 1,
        q = 2, res;
    for (int i = 3; i <= n; ++i){
        res = p + q;
        p = q;
        q = res;
    }
    return res;
}
