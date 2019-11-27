# -*- coding:utf-8 -*-

class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

# 方法1.我的方法。
# 方法1，我的方法。创建一个用于保存原链表-复制链表对应结点的字典
# 先遍历原链表，把next关系复制好。新建一个结点的同时，把原链表结点-复制链表结点键值对放到字典里
# 再遍历原链表，把random关系复制好。通过原链表-复制链表对应结点字典，找到random关系对应的结点
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

# 方法2，思路：
    1. 把复制的结点链接在原始链表的每一对应结点后面
    2. 把复制的结点的random指针指向被复制结点的random指针的下一个结点
    3. 拆分成两个链表，奇数位置为原链表，偶数位置为复制链表，注意复制链表的最后一个结点的next指针不能跟原链表指向同一个空结点None，next指针要重新赋值None(判定程序会认定你没有完成复制）
    class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead):
        if not pHead:
            return None
         
        dummy = pHead
         
        # first step, N' to N next
        while dummy:
            dummynext = dummy.next
            copynode = RandomListNode(dummy.label)
            copynode.next = dummynext
            dummy.next = copynode
            dummy = dummynext
         
        dummy = pHead
         
        # second step, random' to random'
        while dummy:
            dummyrandom = dummy.random
            copynode = dummy.next
            if dummyrandom:
                copynode.random = dummyrandom.next
            dummy = copynode.next
         
        # third step, split linked list
        dummy = pHead
        copyHead = pHead.next
        while dummy:
            copyNode = dummy.next
            dummynext = copyNode.next
            dummy.next = dummynext
            if dummynext:
                copyNode.next = dummynext.next
            else:
                copyNode.next = None
            dummy = dummynext
 
        return copyHead
