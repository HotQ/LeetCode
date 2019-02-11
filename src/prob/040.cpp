#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    void recu(vector<vector<int>> & ans, vector<int> &crt, vector<int> & candidates, int start, int subtarget){
        if(subtarget<0) return;
        if(subtarget == 0) { ans.push_back(crt); return;}
        for(int i = start ;i<candidates.size() ;++i){
            if(i>start && candidates[i] == candidates[i-1]) continue;
            crt.push_back(candidates[i]);
            recu(ans, crt, candidates, i+1, subtarget - candidates[i]);
            crt.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> crt;
        recu(ans, crt, candidates, 0, target);
        return ans;
    }
};

int main(){

    vector<int> n = {10,1,2,7,6,1,5};
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(n,8);
    for(auto v : ans){
        for(auto i : v) cout << i <<'\t';
        cout<< endl;
    }
}
