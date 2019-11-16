# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 方法1：常规解法，同C++
class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        if not pRoot1 or not pRoot2:
            return False
        return self.is_subtree(pRoot1, pRoot2) or self.HasSubtree(pRoot1.left, pRoot2) or self.HasSubtree(pRoot1.right, pRoot2)
      
    def is_subtree(self, A, B):
        if not B:
            return True
        if not A or A.val != B.val:
            return False
        return self.is_subtree(A.left,B.left) and self.is_subtree(A.right, B.right)

# 方法2：神级解法，将树转化为前序遍历字符串！
# 但是经过思考、举例，这个代码是有bug的，因为前序遍历不能代表一棵树的结构。
class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
		# 将树转化为前序遍历字符串返回。（相当于把一棵树压扁为一个字符串）
        def convert(p):
            if p: # 当字符串不为空串时
                return str(p.val) +  convert(p.left) + convert(p.right)
            else:
                return ""
		# 看目标字符串（目标树）是否是该字符串的子串
        return convert(pRoot2) in convert(pRoot1) if pRoot2 else False
        
