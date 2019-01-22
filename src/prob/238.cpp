class Solution{
  public:
    vector<int> productExceptSelf(vector<int> &nums){
        vector<int> res(nums);
        auto size = res.size();
        int tmp1 = nums[0], 
            tmp2 = res[size - 1];
        nums[0] = 1, res[size - 1] = 1;
        for (int i = 1; i < size; ++i){
            tmp1 *= nums[i - 1];
            tmp2 *= res[size - i];
            swap(nums[i], tmp1);
            swap(res[size - 1 - i], tmp2);
        }
        for (int i = 0; i < size; ++i)
            res[i] *= nums[i];
        
        return res;
    }
};
