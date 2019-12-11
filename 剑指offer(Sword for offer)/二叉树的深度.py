# 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 极简递归方法
class Solution:
    def TreeDepth(self, r):
        if not r:
            return 0
        return max(1+self.TreeDepth(r.left), 1+self.TreeDepth(r.right))
        
