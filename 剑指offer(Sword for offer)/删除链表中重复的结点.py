# 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
# 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

# 方法1：非递归，前后指针法
class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        result=ListNode(0)
        res=result
        result.next=pHead
        tmp=pHead
        while tmp and tmp.next:
            if tmp.val==tmp.next.val:
                while tmp.next and tmp.val==tmp.next.val:
                    tmp=tmp.next
            else:
                res.next=tmp
                res=res.next
            tmp=tmp.next
        res.next=tmp
        return result.next
        
# 方法2：递归
class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if pHead is None or pHead.next is None:
            return pHead
        head1 = pHead.next
        if head1.val != pHead.val:
            pHead.next = self.deleteDuplication(pHead.next)
        else:
            while pHead.val == head1.val and head1.next is not None:
                head1 = head1.next
            if head1.val != pHead.val:
                pHead = self.deleteDuplication(head1)
            else:
                return None
        return pHead
        
