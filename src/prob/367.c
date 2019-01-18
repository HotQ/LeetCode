bool isPerfectSquare(int num){
    if (num == 1) return true;
    int lo = 1, hi = num;
    for (; lo < hi;){
        int mid = lo + (hi - lo) / 2,
            tmp = num / mid;
        if ((mid - tmp) < 3 && (mid - tmp) > -3 && (mid * mid == num || tmp * tmp == num)) return true;
        else if (tmp < mid) hi = mid - 1;
        else                lo = mid + 1;
    }
    if (lo * lo == num || hi * hi == num) return true;
    return false;
}
