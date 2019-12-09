// 输入两个链表，找出它们的第一个公共结点。

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 方法1：我的方法。还需要修改细节，未能通过牛客测试用例。
// 先各遍历一遍俩链表，将其结点指针分别保存在两个数组中
// 然后对齐俩数组的尾部，从后往前遍历俩数组。因为俩链表从相同结点开始就合成一条链表了，
// 所以俩数组从后往前遇到的最后一对相等的结点x时，x结点就是两链表第一个相同的结点了。时间复杂度为O(n)。
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* h1, ListNode* h2){
		if(!h1 || !h2){return NULL;}
		if(h1 == h2){return h1;}
		// 用两个数组保存两个链表的结点指针
        vector<ListNode*> nodes1;
		vector<ListNode*> nodes2;
		ListNode* p1 = h1;
		ListNode* p2 = h2;
		// 将两个链表保存到数组中
		while(p1){
			nodes1.push_back(p1);
			p1 = p1->next;
		}
		while(p2){
			nodes2.push_back(p2);
			p2 = p2->next;
		}
		// 从后往前遍历两个数组，找到第一个相同的结点
		ListNode* ans = NULL;
		for(int i = nodes1.size()-1, j = nodes2.size()-1; i >=0, j >=0; --i, --j){
			if(nodes1[i] == nodes2[j]){
				ans = nodes1[i];
			}
		}
		return ans;
    }
};

// 方法2：常规的普通解法
// 开始遍历两遍链表获取两个表的长度，比较长度让长的一个先走差值个步长，再两个一起走（快慢指针思想，链表问题的一般性思路）
// 因为如果有相同结点，则俩链表的最后几个结点必定是相同的，所以让长的链表先走，等到俩链表一样长的时候，再同步比较
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
          if(pHead1==NULL||pHead2==NULL)return NULL;
          //首先遍历两个链表获取长度
          ListNode *pNode1=pHead1,*pNode2=pHead2;
          int listLength1=0,listLength2=0;
          while(pNode1!=NULL){
                ++listLength1;
                pNode1=pNode1->next;
          }
          while(pNode2!=NULL){
                ++listLength2;
                pNode2=pNode2->next;
          }
          //比较长度，长的先走dist步
          pNode1=pHead1;
          pNode2=pHead2;
          if(listLength1>listLength2){
              for(int i=0;i<listLength1-listLength2;i++){
                pNode1=pNode1->next;
              }
          }
          else if(listLength1<listLength2){
              for(int i=0;i<listLength2-listLength1;i++){
                  pNode2=pNode2->next;
              }
          }
          while(pNode1!=NULL&&pNode2!=NULL&&pNode1!=pNode2){
              pNode1=pNode1->next;
              pNode2=pNode2->next;
          }
          return pNode1;
    }
};


// 方法3：网友的强悍精简解法。
// 用两个指针扫描”两个链表“，最终两个指针到达 null 或者到达公共结点。
// 长度相同有公共结点，第一次就遍历到；没有公共结点，走到尾部NULL相遇，返回NULL
// 长度不同有公共结点，第一遍差值就出来了，第二遍一起到公共结点；没有公共，一起到结尾NULL。
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
};

