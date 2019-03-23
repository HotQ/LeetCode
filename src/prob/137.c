class Solution {
public:
	int singleNumber(vector<int>& nums) {
		char tmp[32] = {};
		for (auto& n : nums) {
			bitset<32> crt = n;
			for (int i = 0; i < 32; ++i)
				if (crt[i])
					if (tmp[i] == 2) tmp[i] = 0;
					else tmp[i] += 1;
		}

		if (tmp[31])
			for (int i = 0; i < 31; ++i)
				tmp[i] = 1 - tmp[i];
		int ans = 0;
		for (int i = 30; i >= 0; --i)
			ans = (ans << 1) + tmp[i];

		return tmp[31] == 0 ? ans : -ans - 1;
	}
};
