#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define NULL __null
using namespace std;

class Solution
{
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> list1;
        vector<int> list2;
        recu(root, sum, list1, list2, 0);
        return list1;
    }
    void recu(TreeNode *crt, int sub, vector<vector<int>> &lst1, vector<int> &lst2, int layer)
    {
        if (crt == NULL)
            return;
        ++layer;
        if (lst2.size() < layer) lst2.push_back(crt->val);
        else                     lst2.at(layer - 1) = crt->val;

        if (crt->left == NULL && crt->right == NULL)
            if (crt->val == sub){
                vector<int> lst3(lst2.begin(), lst2.begin() + layer);
                lst1.push_back(lst3);
            }
            else return;

        recu(crt->left, sub - crt->val, lst1, lst2, layer);
        recu(crt->right, sub - crt->val, lst1, lst2, layer);
    }
};
