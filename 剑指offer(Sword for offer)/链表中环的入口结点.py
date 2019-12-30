# 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        #遍历链表，环的存在，遍历遇见的第一个重复的即为入口节点
        tempList = []
        p = pHead
        while p:
            if p in tempList:
                return p
            else:
                tempList.append(p)
            p = p.next
