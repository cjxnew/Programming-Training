// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

#include<iostream>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL){}
};

// 方法1：我的方法。定义一个新链表指针和两个游标，两个游标分别指向两个链表头，对应元素小的游标插到新链表的后面，然后移动游标。
class Solution{
public:
	ListNode* Merge(ListNode* h1, ListNode* h2){
		if(!h1 && !h2){return NULL;}
		ListNode* m = new ListNode(0);
		ListNode* tm = m;
		ListNode* t1 = h1;
		ListNode* t2 = h2;
		while(t1 && t2){
			if(t1->val < t2->val){
				m->next = t1;
				m = m->next;
				t1 = t1->next;
			}else{
				m->next = t2;
				m = m->next;
				t2 = t2->next;
			}
		}
		m->next = (t1)?(t1):(t2);
		return tm->next;
	}
};

// 方法2：递归。当有一个链表为空时，返回另一个链表。但一个链表头结点h1比另一个链表头结点h2小时，递归调用函数Merge(h1->next, h2)。
class Solution{
public:
	ListNode* Merge(ListNode* h1, ListNode* h2){
		if(h1 == NULL){
           return h2;
       }
       if(h2 == NULL){
           return h1;
       }
       if(h1->val <= h2->val){
           h1->next = Merge(h1->next, h2);
           return h1;
       }else{
           h2->next = Merge(h1, h2->next);
           return h2;
       }
	}
};


