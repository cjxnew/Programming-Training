//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
           val(x), next(NULL) {
     }
};

// 方法：建立两个vector，一个用于接收顺序的链表元素，一个用于倒序排列这些元素
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arrayList;
        vector<int> rearrayList;
		ListNode* h = head;
		while(h != NULL){
			arrayList.push_back(h->val);
			h = h->next;
		}
        int len = arrayList.size();
        for(int i = len - 1; i >= 0; --i){
            rearrayList.push_back(arrayList[i]);
        }
		return rearrayList;
    }
};
