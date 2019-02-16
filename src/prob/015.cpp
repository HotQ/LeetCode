class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int size = nums.size();
		sort(nums.begin(), nums.end());
		for (int h = 0; h < size - 2; ++h) {
			if ((h > 0) && (nums[h] == nums[h - 1]))
				continue;
			int i = h + 1,
				j = size - 1;
			while (i < j) {
				if (i - 1 > h && nums[i] == nums[i - 1]) {
					++i;
					continue;
				}
				int sum = nums[h] + nums[i] + nums[j];
				if (sum == 0) ans.push_back({ nums[h],nums[i++],nums[j--] });
				else if (sum > 0) --j;
				else              ++i;
			}
		}
		return ans;
	}
};
