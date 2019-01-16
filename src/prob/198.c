int rob(int *nums, int numsSize){
    int *status = (int *)malloc(numsSize * sizeof(int)), res;
    status[0] = nums[0];
    status[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; ++i){
        int t1 = nums[i] + status[i - 2],
            t2 = status[i - 1];
        status[i] = t1 > t2 ? t1 : t2;
    }
    res = status[numsSize - 1];
    free(status);
    return res;
}
