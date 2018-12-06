int smallestRangeI(int* A, int ASize, int K) {
    if(ASize <= 1)
        return 0;
    int min = A[0],
        max = A[0];
    for(int i = 1; i < ASize; ++i){
        if(min > A[i]) min = A[i];
        if(max < A[i]) max = A[i];
    }
    int res = max-min-2 * K;
    return res < 0 ? 0 : res;
}
