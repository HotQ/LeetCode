#include <stdlib.h>
#include <stdbool.h>

int cmpfunc (const void * a, const void * b);

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);
 
    *returnSize = 0;
    int **res = (int **)malloc(sizeof(int *)),
        crtCapacity = 1;

    for (int h = 0; h < numsSize - 2; ++h)
    {
        if ((h > 0) && (nums[h] == nums[h - 1]))
            continue;

        int target = 0 - nums[h],
            i = h + 1,
            j = numsSize - 1;
        while (i < j)
        {
            if (i - 1 > h && nums[i] == nums[i - 1])
            {
                ++i;
                continue;
            }
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                int *crtSolu = (int *)malloc(3 * sizeof(int));
                crtSolu[0] = nums[h];
                crtSolu[1] = nums[i];
                crtSolu[2] = nums[j];
                ++(*returnSize);
                if (crtCapacity < *returnSize)
                {
                    crtCapacity *= 2;
                    res = (int **)realloc(res, crtCapacity * sizeof(int *));
                }
                res[(*returnSize) - 1] = crtSolu;
                ++i;
                --j;
            }
            else if (sum < target)
                ++i;
            else
                --j;
        }
    }
    return res;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
