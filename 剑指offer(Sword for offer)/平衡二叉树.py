# 输入一棵二叉树，判断该二叉树是否是平衡二叉树。

# 思路见cpp版
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def IsBalanced_Solution(self, r):
        if not r:
            return True
        if abs(self.TreeDeep(r.left) - self.TreeDeep(r.right)) > 1:
            return False
        return self.IsBalanced_Solution(r.left) and self.IsBalanced_Solution(r.right)
    
    def TreeDeep(self, r):
        if not r:
            return 0
        return max(1+self.TreeDeep(r.left), 1+self.TreeDeep(r.right))
        
