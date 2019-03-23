/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<pair<TreeNode*, int>> que;
		vector<vector<int>> ans;
		vector<int> layer;
		int layerno = 1;
		if (root == nullptr) return ans;
		que.push(make_pair(root, 1));
		while (que.size()) {
			auto crtnode = que.front();
			if (crtnode.second != layerno) { ++layerno; ans.push_back(layer); layer.clear(); }
			layer.push_back(crtnode.first->val);
			if (crtnode.first->left  != nullptr) que.push(make_pair(crtnode.first->left,  crtnode.second + 1));
			if (crtnode.first->right != nullptr) que.push(make_pair(crtnode.first->right, crtnode.second + 1));
			que.pop();
		}
		if (layer.size())ans.push_back(layer);
		return ans;
	}
};
