class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		set<vector<int>> resUni;
		int size = nums.size();
		recu(resUni, nums, 0, size);
		for (auto i : resUni)
			res.push_back(i);
		return res;
	}
	void recu(set<vector<int>> &resUni, vector<int>& nums, int ind, int len) {
		if (len == ind)
			resUni.insert(nums);
		for (int i = ind; i < len; ++i) {
            if(i != ind && nums[ind] == nums[i])continue;

			swap(nums[ind], nums[i]);
			recu(resUni, nums, ind + 1, len);
			swap(nums[ind], nums[i]);
		}
	}
};
