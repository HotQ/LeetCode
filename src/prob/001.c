/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize - 1; ++i)
    {
        int subTarget = target - nums[i];
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[j] == subTarget)
            {
                int *res = (int *)malloc(2 * sizeof(int));
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return NULL;
}
