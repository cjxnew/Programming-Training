# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 设置两个指针，快指针p1，慢指针p2，先让p1走k-1步，然后再一起走，直到p1为最后一个结点时，p2即为倒数第k个节点 
class Solution:
    def FindKthToTail(self, head, k):
        # write code here
		if k == 0:
			return None
		p1 = p2 = head
		for i in range(0, k):
			if p1 == None:
				return None
			p1 = p1.next
		while p1 != None:
			p1 = p1.next
			p2 = p2.next
		return p2
			
