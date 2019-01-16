int rob(int *nums, int numsSize)
{
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int *status = (int *)malloc((numsSize - 1) * sizeof(int)), res1, res2;
    status[0] = nums[0];
    status[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize - 1; ++i){
        int t1 = nums[i] + status[i - 2],
            t2 = status[i - 1];
        status[i] = t1 > t2 ? t1 : t2;
    }
    res1 = status[numsSize - 2];
    
    status[0] = nums[1];
    status[1] = nums[1] > nums[2] ? nums[1] : nums[2];
    for (int i = 2; i < numsSize - 1; ++i){
        int t1 = nums[i + 1] + status[i - 2],
            t2 = status[i - 1];
        status[i] = t1 > t2 ? t1 : t2;
    }
    res2 = status[numsSize - 2];
    free(status);
    return res1 > res2 ? res1 : res2;
}
