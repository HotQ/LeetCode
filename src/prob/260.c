/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int axorb = 0,
        *ans =(int *)calloc(*returnSize =2,sizeof(int)),
        bflag ;
    for(int i = 0; i<numsSize;++i)
        axorb ^= nums[i];
    
    bflag = axorb & ~(axorb -1);

    for(int i = 0; i<numsSize;++i)
        if(bflag & nums[i]) ans[0]^= nums[i];
        else                ans[1]^= nums[i];
    
    return ans;
}
