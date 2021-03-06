class Solution{
  public:
    int candy(vector<int> &ratings){
        int size = ratings.size();
        vector<int> tmp(size, 1);
        for (int i = 1; i < size; ++i)      if (ratings[i] > ratings[i - 1])                         tmp[i] = tmp[i - 1] + 1;
        for (int i = size - 2; i >= 0; --i) if (ratings[i] > ratings[i + 1] && tmp[i] <= tmp[i + 1]) tmp[i] = tmp[i + 1] + 1;
        return accumulate(tmp.begin(), tmp.end(), 0);
    }
};