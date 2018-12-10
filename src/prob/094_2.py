# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:    
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        vec = []

        def recu( root , vector):
            if(root == None):
                return        
            recu(root.left,vector)
            vector.append(root.val)
            recu(root.right,vector)
            
        recu(root, vec)
        return vec
