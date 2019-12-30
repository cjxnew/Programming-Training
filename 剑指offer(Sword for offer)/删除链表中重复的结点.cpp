// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
// 返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

#include<iostream>
#include<map>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

// 方法1：我的方法。
// 先遍历一遍链表，找到哪些值为重复值
// 再遍历一遍链表，删除重复值对应的结点
class Solution {
public:
	ListNode* deleteDuplication(ListNode* h){
		if(!h){return nullptr;}
		map<int, int> value_time_dict; // 记录每个值出现次数的字典
		ListNode* h1 = h;
		while(h1){ // 先遍历一遍链表，找到哪些值为重复值
			value_time_dict[h1->val] += 1;
			h1 = h1->next;
		}
		while(value_time_dict[h->val] > 1){ // 假如头结点也属于重复值，则将头结点往后移
			h = h->next;
			if(!h){return nullptr;} // 要特别注意！若h为nullptr，执行nullptr->val将发生段错误！！！
		}
		ListNode* head = h;
		while(h->next){ // 再遍历一遍链表，删除重复值对应的结点
			if(value_time_dict[h->next->val] > 1){
				ListNode* tmp = h->next;
				while(value_time_dict[tmp->val] > 1){
					tmp = tmp->next;
					if(!tmp){
						h->next = tmp;
						return head;
					}
				}
				h->next = tmp;
			}
			h = h->next;
		}
		return head;
	}
};

// 方法2：这道题我忽略了一个细节，就是链表是排序的，所以重复的值是放在相邻结点中的。
// 非递归的代码：
// 1. 首先添加一个头节点，以方便碰到第一个，第二个节点就相同的情况
// 2.设置 pre ，last 指针， pre指针指向当前确定不重复的那个节点，而last指针相当于工作指针，一直往后面搜索。
class Solution {
public:
	ListNode* deleteDuplication(ListNode* h){
		if(!h || !h->next){return h;}
		ListNode* Head = new ListNode(0);
		Head->next = h;
		ListNode* pre = Head;
		ListNode* last = Head->next;
		while(last){
			if(last->next && last->val == last->next->val){
				// 找到最后一个重复节点
				while(last->next && last->val == last->next->val){
					last = last->next;
				}
				pre->next = last->next;
				last = last->next;
			}else{
				pre = pre->next;
				last = last->next;
			}
		}
		return Head->next; 
	}
};


// 方法3：递归方法
class Solution {
public:
	ListNode* deleteDuplication(ListNode* h){
		if (!h || !h->next){
			return h;
		}
		ListNode* current;
		if(h->next->val == h->val){
			current = h->next->next;
			while(current && current->val == h->val){
				current = current->next;
			}
			return deleteDuplication(current);                     
		}
		else {
			current = h->next;
			h->next = deleteDuplication(current);
			return h;
		}    
	}
};

