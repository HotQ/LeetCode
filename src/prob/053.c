inline int max(int x, int y){
    return x > y ? x : y;
}
int maxSubArray(int* nums, int numsSize) {
    int max_ending_here = nums[0],
        max_so_far = nums[0];
    for (int i = 1; i < numsSize; ++i){
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
