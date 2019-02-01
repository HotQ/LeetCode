class Solution{
  public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> ans = {vector<int>()};
        for (auto n : nums){
            int size = ans.size();
            for (int i = 0; i < size; ++i){
                ans.push_back(ans[i]);
                ans.back().push_back(n);
            }
        }
        return ans;
    }
};
