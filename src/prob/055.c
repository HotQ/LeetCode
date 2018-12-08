bool canJump(int* nums, int numsSize) {
	int clr = numsSize - 1;
	for (int i = numsSize - 2; i >= 0; --i)
		if (i + nums[i] >= clr)clr = i;
	return clr == 0 ? true : false;
}
