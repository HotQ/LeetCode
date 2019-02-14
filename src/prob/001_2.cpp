class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, vector<int>> index;
		for (int i = 0; i < nums.size(); ++i) 
			index[nums[i]].push_back(i);
		
		vector<int>ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			auto res = lower_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
			if (res != nums.end() && *res == target - nums[i]) {
				ans.push_back(index[nums[i]][0]);
				if (*res == nums[i]) ans.push_back(index[*res][1]);
				else                 ans.push_back(index[*res][0]);
			}
		}
		return ans;
	}
};
