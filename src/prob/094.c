#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int stackCap = 10,
        top = -1,
        vecCap = 10,
        *vec = (int *)malloc(vecCap * sizeof(int)),
        vecSize = 0;
    struct TreeNode **stack = (struct TreeNode **)malloc(stackCap * sizeof(struct TreeNode *)),
                    *crtNode = root;


    while(crtNode!=NULL || top>-1){
        while(crtNode!=NULL){
            stack[++top]=crtNode;
            crtNode=crtNode->left;
        }
        if(top>-1){
             ++vecSize;
            if (vecSize > vecCap)
            {
                vecCap *= 2;
                vec = (int *)realloc(vec, vecCap * sizeof(int));
            }
            vec[vecSize - 1] = stack[top]->val;
            crtNode=stack[top--]->right;
        }
    }

    *returnSize=vecSize;
    return vec;
}
