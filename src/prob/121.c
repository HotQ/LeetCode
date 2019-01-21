inline int max(int x, int y){
    return x > y ? x : y;
}
int maxProfit(int *prices, int pricesSize){
    if (pricesSize < 2)
        return 0;
    for (int i = pricesSize - 1; i > 0; --i)
        prices[i] = prices[i] - prices[i - 1];

    // Kadane
    int max_ending_here = 0,
        max_so_far = 0;
    for (int i = 1; i < pricesSize; ++i){
        max_ending_here = max(0, max_ending_here + prices[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
