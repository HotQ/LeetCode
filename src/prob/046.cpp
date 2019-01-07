#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> base;
        set<int> last;
        for(int n : nums)last.insert(n);
        recu(res, base, last, nums.size());
        return res;
    }
    void recu(vector<vector<int>> &res, vector<int> base, set<int> last, int len){
        if(len == 1){
            base.push_back(*(last.begin()));
            res.push_back(base);
            return;
        }
        for(int n : last){
            vector<int> tmpvec = base;
            set   <int> tmpset = last;
            tmpvec.push_back(n);
            tmpset.erase(n);
            recu(res, tmpvec, tmpset, len -1);
        }
    }
};
