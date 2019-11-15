# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 用pre记录当前节点的前一个节点，用next记录当前节点的后一个节点
class Solution:
    # 返回ListNode
    def ReverseList(self, head):
        # write code here
		if not head:
			return None
		pre = None
		while head:
			nex = head.next
			head.next = pre
			pre = head
			head = nex
		return pre
			
