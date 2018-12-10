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
        stack = []
        vec = []
        crtNode = root

        while(crtNode != None or len(stack) > 0):
            while(crtNode != None):
                stack.append(crtNode)
                crtNode = crtNode.left
            if(len(stack) > 0):
                vec.append(stack[-1].val)
                crtNode = stack.pop().right
        return vec
