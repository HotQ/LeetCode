#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> base(nums);
        set<int> last;
        for(int n : nums)last.insert(n);
        recu(res, base, 0, last, nums.size());
        return res;
    }
    void recu(vector<vector<int>> &res, vector<int> &base, int len1, set<int> last, int len){
        if(len == 1){
            base[len1]=*(last.begin());
            res.push_back(base);
            return;
        }
        
        for(int n : last){
            set<int> tmpset = last;
            base[len1]=n;
            tmpset.erase(n);
            recu(res, base, len1+1, tmpset, len -1);
        }
    }
};
