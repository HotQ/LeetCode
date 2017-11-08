#include <vector>
using std::vector;

class Solution
{
  public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        switch (nums.size())
        {
        case 0:
            return 0;
        case 1:
            return 1;
        }

        // length of longest continuous increasing subsequence
        int len = 1, _len = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++_len;
            }
            else
            {
                if (_len > len)
                    len = _len;
                _len = 1;
            }
        }
        return (len > _len ? len : _len);
    }
};