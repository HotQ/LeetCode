int mySqrt(int x) {
    int hi = x/2+1,
        lo = 0,
        mid ;
    if(x<2)return x;

    // [lo, hi)
    while(lo < hi){
        mid = (hi-lo)/2+lo;
        (x / mid < mid) ? (hi = mid) : (lo = mid+1);  
    }
    return lo-1;
}
