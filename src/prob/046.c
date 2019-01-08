#include <stdlib.h>
#include <string.h>
#define swap(a,b) {int t = (a);(a) = (b);(b)=t;}
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recu(int **res, int *rind, int *nums, int ind, int len);
int** permute(int* nums, int numsSize, int* returnSize) {
	*returnSize = 1;
	for (int i = 2; i <= numsSize; ++i)(*returnSize) *= i;
	int rind = -1,
		**res = (int**)malloc(*returnSize * sizeof(int*));
	recu(res, &rind, nums, 0, numsSize);
	return res;
}
void recu(int **res, int *rind, int *nums, int ind, int len) {
	if (len == ind) {
		size_t size = len * sizeof(int);
		int *tmp = (int *)malloc(size);
		if (tmp) memcpy(tmp, nums, size);
		res[++(*rind)] = tmp;
		return;
	}
	for (int i = ind; i < len; ++i) {
		swap(nums[ind], nums[i]);
		recu(res, rind, nums, ind + 1, len);
		swap(nums[ind], nums[i]);
	}
}
