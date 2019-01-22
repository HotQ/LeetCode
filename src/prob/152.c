inline int max3(int x, int y, int z){
    int temp = x > y ? x : y;
    return temp > z ? temp : z;
}
inline int max(int x, int y){
    return x > y ? x : y;
}
inline int min3(int x, int y, int z){
    int temp = x < y ? x : y;
    return temp < z ? temp : z;
}
int maxProduct(int *nums, int numsSize){
    int maxsofar = nums[0], maxhere = nums[0],
        minsofar = nums[0];
    for (int i = 1; i < numsSize; ++i){
        int maxheretmp = max3(nums[i], maxhere * nums[i], minhere * nums[i]),
            minheretmp = min3(nums[i], maxhere * nums[i], minhere * nums[i]);
        maxhere = maxheretmp;
        minhere = minheretmp;
        maxsofar = max(maxsofar, maxhere);
    }
    return maxsofar;
}
