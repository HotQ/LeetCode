#include <stdbool.h>
#include <stdlib.h>
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int sum)
{
    if (root != NULL){
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    return false;
}
