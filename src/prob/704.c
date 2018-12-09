int search(int* nums, int numsSize, int target) {
	// [lo, hi)
	int lo = 0,
		hi = numsSize,
		mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (nums[mid] < target) lo = mid + 1;
		else hi = mid;
	}
	return nums[lo] == target ? lo : -1;
}
