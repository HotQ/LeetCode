#define swap(a, b)    \
    {                 \
        int temp = a; \
        a = b;        \
        b = temp;     \
    }
int partition(int A[], int S[], int lo, int hi);
void quickSort(int A[], int S[], int lo, int hi);
int *quickSortIndex(int A[], int lo, int hi);

int *twoSum(int *nums, int numsSize, int target)
{
    int *index = quickSortIndex(nums, 0, numsSize - 1),
        i = 0,
        j = numsSize - 1;
    while (i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum == target)
        {
            int *res = (int *)malloc(2 * sizeof(int));
            if (index[i] < index[j])
            {
                res[0] = index[i];
                res[1] = index[j];
            }
            else
            {
                res[0] = index[j];
                res[1] = index[i];
            }
            return res;
        }else if(sum < target)
            ++i;
        else
            --j; 
    }

    return NULL;
}

int partition(int A[], int S[], int lo, int hi)
{
    int pivot = A[hi],
        i = lo - 1;
    for (int j = lo; j <= hi - 1; ++j)
    {
        if (A[j] < pivot && i != j)
        {
            ++i;
            swap(S[i], S[j]);
            swap(A[i], A[j]);
        }
    }
    ++i;
    swap(S[i], S[hi]);
    swap(A[i], A[hi]);
    return i;
}
void quickSort(int A[], int S[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(A, S, lo, hi);
        quickSort(A, S, lo, p - 1);
        quickSort(A, S, p + 1, hi);
    }
}
int *quickSortIndex(int A[], int lo, int hi)
{

    int len = hi - lo + 1,
        *index = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i)
    {
        index[i] = i;
    }
    quickSort(A, index, lo, hi);
    return index;
}
