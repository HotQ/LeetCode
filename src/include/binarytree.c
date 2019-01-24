#include "binarytree.h"

static void inorderprint(struct TreeNode* tree,int dir, int layer,int drawlines){
    if(tree == NULL)return ;

    int pow2[]={0x0,0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000,0x10000,0x20000,0x40000,0x80000,0x100000,0x200000,0x400000,0x800000,0x1000000,0x2000000,0x4000000,0x8000000,0x10000000,0x20000000,0x40000000};
    char s[3][4] = {"┏","┃","┗"};

    inorderprint(tree->right,-1, layer+1,(dir==-1?pow2[layer]:drawlines+pow2[layer]));

    for(int i = 1;i<layer;++i) printf("%*s%s",3,"",(drawlines & pow2[i]? (i==layer-1?s[dir+1]:"┃"):" "));
    printf("%2d ",tree->val);
    if(tree->right==NULL && tree->left) printf("┓");
    if(tree->left && tree->right)       printf("┫");
    if(tree->left==NULL && tree->right) printf("┛");
    printf("\n");

    inorderprint(tree->left,1,layer+1,(dir==1?pow2[layer]:drawlines+pow2[layer]));
}

void printBiTree(struct TreeNode* tree){
    inorder(tree,0,1,0);
    return ;
}
