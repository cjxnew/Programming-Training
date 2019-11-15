# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 方法1：递归
class Solution:
    # 返回合并后列表
    def Merge(self, h1, h2):
        # write code here
		if not h1:
			return h2
		elif not h2:
			return h1
		else:
			if h1.val <= h2.val:
				h1 = Merge(h1.next, h2)
				return h1
			else:
				h2 = Merge(h1, h2.next)
				return h2
