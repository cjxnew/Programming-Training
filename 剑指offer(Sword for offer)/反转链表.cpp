// 输入一个链表，反转链表后，输出新链表的表头。

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 方法1：我的方法，新建一个链表，用头插法插入原链表的结点。
// 注意因为要使用头插法，故要建立一个在头结点前面的头指针结点，但是在函数返回的时候返回的还是头结点，即返回头指针结点的下一个结点。
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(!pHead){return NULL;}
		ListNode* rHead = new ListNode(0);
		while(pHead){
			ListNode* node = new ListNode(pHead->val);
			node->next = rHead->next;
			rHead->next = node;
			pHead = pHead->next;
		}
		return rHead->next;
    }
};

// 方法2：用pre记录当前节点的前一个节点，用next记录当前节点的后一个节点
// 1.当前节点a不为空，进入循环，先记录a的下一个节点位置next = b;再让a的指针指向pre；
// 2.移动pre和head的位置，正因为刚才记录了下一个节点的位置，所以该链表没有断，我们让head走向b的位置；
// 3.当前节点为b不为空，先记录下一个节点的位置，让b指向pre的位置即a的位置，同时移动pre和head；
// 4.当前节点c不为空，记录下一个节点的位置，让c指向b，同时移动pre和head，此时head为空，跳出，返回pre。
class Solution {
    ListNode* ReverseList(ListNode* head) {
         // 判断链表为空或长度为1的情况
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* pre = NULL; // 当前节点的前一个节点
        ListNode* next = NULL; // 当前节点的下一个节点
        while( head != NULL){
            next = head->next; // 记录当前节点的下一个节点位置；
            head->next = pre; // 让当前节点指向前一个节点位置，完成反转
            pre = head; // pre 往右走
            head = next;// 当前节点往右继续走
        }
        return pre;
    }
};

// 方法3：递归。递归的方法其实是非常巧的，它利用递归走到链表的末端，然后再更新每一个node的next值，
// 实现链表的反转。而newhead 的值没有发生改变，为该链表的最后一个结点，所以，反转后，我们可以得到新链表的head。
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //如果链表为空或者链表中只有一个元素
        if(pHead==NULL||pHead->next==NULL) return pHead;
         
        //先反转后面的链表，走到链表的末端结点
        ListNode* pReverseNode=ReverseList(pHead->next);
         
        //再将当前节点设置为后面节点的后续节点
        pHead->next->next=pHead;
        pHead->next=NULL;
         
        return pReverseNode;
    }
};
