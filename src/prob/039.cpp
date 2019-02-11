class Solution {
public:
    void recu(vector<vector<int>> & ans, vector<int> &crt, vector<int>::const_iterator start, vector<int>::const_iterator end, int subtarget){
        if(subtarget<0) return;
        if(subtarget == 0) { ans.push_back(crt); return;}
        for(; start != end; ++start){
            crt.push_back(*start);
            recu(ans, crt, start, end, subtarget - *start);
            crt.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> crt;
        recu(ans, crt, candidates.cbegin(), candidates.cend(), target);
        return ans;
    }
};
