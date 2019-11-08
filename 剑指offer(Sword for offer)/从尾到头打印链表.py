 -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 方法一：使用insert函数对列表进行头插法
class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        head = listNode
        while head:
            l.insert(0, head.val)
            head = head.next
        return l


# 方法2：用[::-1]进行逆序
class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        while listNode:
            l.append(listNode.val)
            listNode = listNode.next
        return l[::-1]
