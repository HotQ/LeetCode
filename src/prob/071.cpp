class Solution {
public:
	string simplifyPath(string path) {
		auto it = path.cbegin(),
			end = path.cend();
		string crtdir, ans;
		vector<string> pathdir;
		while (it != end) {
			if (*it == '/') {
				while (++it != end && *it == '/');
			}
			else {
				crtdir = "";
				while (it != end && *it != '/')            crtdir.push_back(*it++);
				if (crtdir != "." && crtdir != "..")       pathdir.push_back(crtdir);
				else if (crtdir == ".." && pathdir.size()) pathdir.pop_back();
			}
		}
		for (auto i : pathdir) { ans.push_back('/'); ans += i; }
		return pathdir.size() ? ans : "/";
	}
};
