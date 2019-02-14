class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_multimap<int, int> index;
		for (int i = 0; i < nums.size(); ++i)
			index.insert({ nums[i],i });
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++i) {
			auto it_pair = index.equal_range(target - nums[i]);
			if (it_pair.first != it_pair.second && it_pair.first->second != i) {
				ans.push_back(i);
				ans.push_back((it_pair.first)->second);
				break;
			}
		}
		return ans;
	}
};
