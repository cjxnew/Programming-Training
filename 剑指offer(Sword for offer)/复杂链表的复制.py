# -*- coding:utf-8 -*-

class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

# 方法1.我的方法。
class Solution:
    # 返回 RandomListNode
    def Clone(self, h):
        # write code here
        if h == None:
            return None
        # 用于保存原链表-复制链表对应结点的字典
        node_address = {}
        copyH = RandomListNode(h.label)
        node_address[h] = copyH
        tmpH = h
        ansH = toolH = copyH
        # 先遍历原链表，把next关系复制好。新建一个结点的同时，把原链表结点-复制链表结点键值对放到字典里
        while tmpH.next != None:
            node = RandomListNode(tmpH.next.label)
            copyH.next = node
            node_address[tmpH.next] = node
            tmpH = tmpH.next
            copyH = copyH.next
        # 再遍历原链表，把random关系复制好。通过原链表-复制链表对应结点字典，找到random关系对应的结点
        while h != None:
            if h.random == None:
                toolH.random = None
            else:
                toolH.random = node_address[h.random]
            h = h.next
            toolH = toolH.next
            
        return ansH
