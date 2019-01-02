#define swap(a, b)    \
    {                 \
        int temp = a; \
        a = b;        \
        b = temp;     \
    }

int partition(int* A, int lo, int hi){
    int pivot = A[hi],
        i = lo - 1;
    for (int j = lo; j <= hi - 1; ++j){
        if (A[j] < pivot && i != j){
            ++i;
            swap(A[i], A[j]);
        }
    }
    ++i;
    swap(A[i], A[hi]);
    return i;
}

int findKthLargest(int *nums, int numsSize, int k){
    int mid = partition(nums, 0, numsSize - 1),
        tgt = numsSize - k;

    if (mid == tgt) return nums[mid];
    else if(mid < tgt) return findKthLargest(nums + mid + 1,numsSize - mid - 1, k);
    else return findKthLargest(nums, mid, k - (numsSize-mid));
}
