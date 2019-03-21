class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        auto it1 = lower_bound(nums.begin(), nums.end(), target),
             it2 = upper_bound(nums.begin(), nums.end(), target);
        return { it1 == nums.end()  || *it1     != target ? -1 : it1 - nums.begin(),
                 it2 == nums.begin()|| *(--it2) != target ? -1 : it2 - nums.begin()};
    }
};
