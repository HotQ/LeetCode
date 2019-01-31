int fib(int N) {
    if(N == 0)return 0;
    if(N == 1)return 1;
    int p = 0,
        q = 1, res;
    for(int i = 2; i<=N; ++i){
        res = p + q;
        p = q;
        q = res;
    }
    return res;    
}
