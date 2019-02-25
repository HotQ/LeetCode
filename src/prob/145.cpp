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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> stc;
		vector<int> ans;
		TreeNode *p, *b = root;
		int flag;
		if (root) {
			do {
				while (b) {
					stc.push(b);
					b = b->left;
				}
				p = NULL;
				flag = 1;
				while (stc.size() && flag) {
					b = stc.top();
					if (b->right == p) {
						ans.push_back(b->val);
						stc.pop();
						p = b;
					}
					else {
						b = b->right;
						flag = 0;
					}
				}
			} while (stc.size());
		}
		return ans;
	}
};
