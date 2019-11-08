# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, vin):
        # write code here
        if len(pre) == 0:
            return None
        if len(pre) == 1:
            return TreeNode(pre[0])
        else:
            flag = TreeNode(pre[0])
            flag.left = self.reConstructBinaryTree(pre[1:vin.index(pre[0])+1], vin[:vin.index(pre[0])])
            flag.right = self.reConstructBinaryTree(pre[vin.index(pre[0])+1:], vin[vin.index(pre[0])+1:] )
        return flag
