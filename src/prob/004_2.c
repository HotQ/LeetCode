double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    if (nums1Size == 0)
    {
        return ((double)nums2[(nums2Size - 1) / 2] + (double)nums2[nums2Size / 2]) / 2;
    }

    int totleSize = nums1Size + nums2Size,
        cut1 = nums1Size / 2,
        cut2 = totleSize / 2 - cut1,
        Min = 0x80000000,
        Max = 0x7fffffff,
        // for binary search
        low = 0,
        high = nums1Size;

    while (cut1 <= nums1Size)
    {
        cut1 = (low + high) / 2;
        cut2 = totleSize / 2 - cut1;

        int L1 = (cut1 == 0) ? Min : nums1[cut1 - 1],
            L2 = (cut2 == 0) ? Min : nums2[cut2 - 1],
            R1 = (cut1 == nums1Size) ? Max : nums1[cut1],
            R2 = (cut2 == nums2Size) ? Max : nums2[cut2];

        if (L1 > R2)
        {
            high = cut1 - 1;
        }
        else if (L2 > R1)
        {
            low = cut1 + 1;
        }
        else
        {
            if ((nums1Size + nums2Size) % 2 == 0)
            {
                return ((double)((L1 > L2 ? L1 : L2) + (R1 < R2 ? R1 : R2))) / 2;
            }
            else
            {
                return ((cut1 + cut2) * 2 > totleSize) ? (L1 > L2 ? L1 : L2) : (R1 < R2 ? R1 : R2);
            }
        }
    }
    return 0;
}
