class Solution {
public:
	vector<int> partitionLabels(string S) {
		int lo = 0, hi = 0, total = 0, size = S.size();
		int chrstat[26][2];
		map<int, int> stat;
		vector<int> ans;
		for (int i = 0; i < 26; ++i)chrstat[i][0] = -1;
		for (int i = 0; i < size; ++i)
			if (chrstat[S[i] - 'a'][0] == -1) { chrstat[S[i] - 'a'][0] = chrstat[S[i] - 'a'][1] = i; }
			else                                chrstat[S[i] - 'a'][1] = i;

		for (int i = 0; i < 26; ++i) {
			if (chrstat[i][0] != -1)stat[chrstat[i][0]] = chrstat[i][1];
		}
		for (auto i : stat)
			if (i.first > hi) {
				ans.push_back(hi - lo + 1);
				total += hi - lo + 1;
				lo = i.first;
				hi = i.second;
			}
			else if (i.second > hi) hi = i.second;

		if (total != size) ans.push_back(size - total);
		return ans;
	}
};