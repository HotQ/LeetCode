#include <stdlib.h>
#include <stdbool.h>

int partition(int A[], int lo, int hi);
void quickSort(int A[], int lo, int hi);
int *quickSortIndex(int A[], int lo, int hi);

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize)
{
    quicksort(nums, 0, numsSize - 1);
    
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

#define swap(a, b)    \
    {                 \
        int temp = a; \
        a = b;        \
        b = temp;     \
    }

int partition(int A[], int lo, int hi)
{
    int pivot = A[hi],
        i = lo - 1;
    for (int j = lo; j <= hi - 1; ++j)
        if (A[j] < pivot && i != j)
        {
            ++i;
            swap(A[i], A[j]);
        }
    ++i;
    swap(A[i], A[hi]);
    return i;
}

void quicksort(int A[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(A, lo, hi);
        quicksort(A, lo, p - 1);
        quicksort(A, p + 1, hi);
    }
}
