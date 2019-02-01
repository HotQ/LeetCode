class Solution{
  public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> crt = {};
        subsets_recu(ans, nums, crt, 0);
        return ans;
    }
    void subsets_recu(vector<vector<int>> &ans, vector<int> &nums, vector<int> &crt, int step){
        if (step == nums.size()){
            ans.push_back(crt);
            return;
        }
        crt.push_back(nums[step]);
        subsets_recu(ans, nums, crt, step + 1);
        crt.pop_back();
        subsets_recu(ans, nums, crt, step + 1);
    }
};
