class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() == 0) return 0;
		int ans = 0;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == ')') continue;
			int crt = 1;
			for (int j = i + 1; j < s.size(); ++j) {
				if (crt) {
					if (s[j] ==')') {
						--crt;
						if (crt == 0 && j - i+1 > ans)
							ans = j - i+1;
					}else ++crt;
				}
				else {
					if (j - i > ans)ans = j - i;
					if (s[j] == ')' || j == s.size()-1) {
						break;
					}
					++crt;
				}
			}
		}
		return ans;
	}
};
