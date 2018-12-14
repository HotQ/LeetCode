#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)        
        return 0;
    int p = 0;
    for(int i=1; i<numsSize; ++i)
        if(nums[i] != nums[p])
                nums[++p]=nums[i];       
    return p+1;
}
