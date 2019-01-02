int cmpfunc(void *a, void *b){
    return (*(int*)a - *(int*)b);
}

int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    return nums[numsSize-k];
}
