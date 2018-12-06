/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define swap(l,r) {struct TreeNode* t=l;l=r;r=t;}
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL) return NULL;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
