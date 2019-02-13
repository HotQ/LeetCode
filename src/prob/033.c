int search(int *nums, int numsSize, int target)
{
    int lo = 0,
        hi = numsSize - 1;
    if (numsSize == 0) return -1;
    if (numsSize == 1)
        if (nums[0] == target) return 0;
        else                   return -1;

    while (lo < hi){
        int mi = lo + (hi - lo) / 2;
        if (nums[mi] == target) return mi;
        if (nums[lo] == target) return lo;
        if (nums[hi] == target) return hi;

        if (nums[lo] > nums[hi]){
            if (nums[lo] < target){
                if (nums[mi] < target && nums[mi] > nums[lo]) lo = mi + 1;
                else                                          hi = mi - 1;
            }
            else if (target < nums[hi]){
                if (nums[mi] > target && nums[mi] < nums[hi]) hi = mi - 1;
                else                                          lo = mi + 1;
            }
            else return -1;
        }
        else {
            if (target > nums[mi]) lo = mi + 1;
            else                   hi = mi - 1;
        }
    }
    return -1;
}
