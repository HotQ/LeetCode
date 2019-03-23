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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int, int> map2;
		int size = inorder.size();
		if (size == 0) return nullptr;
		for (int i = 0; i < size; ++i)
			map2[inorder[i]] = i;
		return recu(0, size - 1, 0, size - 1, postorder, inorder, map2);
	}

	TreeNode * recu(int lo1, int hi1, int lo2, int hi2, vector<int> & postorder, vector<int> & inorder, unordered_map<int, int> & map2) {
		int rootv = postorder[hi1],
			rooti = map2[rootv];
		TreeNode* root = new TreeNode(rootv);

		root->left  = rooti == lo2 ? nullptr : recu(lo1, lo1 - lo2 + rooti - 1, lo2, rooti - 1, postorder, inorder, map2);
		root->right = rooti == hi2 ? nullptr : recu(hi1 - hi2 + rooti, hi1 - 1, rooti + 1, hi2, postorder, inorder, map2);
		return root;
	}
};
