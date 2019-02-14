class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(auto &str : strs){
            string crt(str);
            sort(crt.begin(), crt.end());
            mp[crt].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto item : mp)
            ans.push_back(std::move(item.second));
        
        return ans;
    }
};
