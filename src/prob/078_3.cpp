class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        int len = pow(2, nums.size());
        for (int i = 0; i < len; ++i){
            int j = i, k = 0;
            ans.push_back({});
            while (j){
                if (j & 1) ans.back().push_back(nums[k]);
                j = j >> 1; ++k;
            }
        }
        return ans;
    }
};
