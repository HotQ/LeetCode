/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool recu(struct TreeNode* root, int* min, int* max) {
	int min1, max1, min2, max2;
	if (root->left == NULL && root->right == NULL) {
		*min = *max = root->val;
		return true;
	}
	if (root->left != NULL && root->right != NULL) {
		bool b1 = recu(root->left, &min1, &max1);
		bool b2 = recu(root->right, &min2, &max2);
		*min = min1;
		*max = max2;
		return b1 && b2&& max1 < root->val&& root->val < min2;
	}
	if (root->left != NULL) {
		bool b1 = recu(root->left, &min1, &max1);
		*min = min1;
		*max = root->val;
		return b1 && max1 < root->val;
	}
	if (root->right != NULL) {
		bool b2 = recu(root->right, &min2, &max2);
		*min = root->val;
		*max = max2;
		return b2 && root->val < min2;
	}
	return false;
}

bool isValidBST(struct TreeNode* root) {
    int tmp;
	return root == NULL ? true : recu(root, &tmp, &tmp);
}
