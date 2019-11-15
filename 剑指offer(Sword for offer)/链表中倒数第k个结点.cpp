// 输入一个链表，输出该链表中倒数第k个结点。

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

// 方法1：我的土方法，注意牛客网的题目默认头结点就是链表的第一个带数据节点。
// 先求链表的长度len，再按倒数第k个点是正数第len-k+1个点来求。
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if(k <= 0 || !pListHead){return NULL;}
		int len = 0, count = 1;
		ListNode *h1 = pListHead, *h2 = pListHead;
		while(h1){
			++len;
			h1 = h1->next;
		}
		if(len < k){return NULL;}
		while(count != len - k + 1){
			h2 = h2->next;
			++count;
		}
		return h2;
    }
};

// 方法2：设置两个指针，快指针p1，慢指针p2，先让p1走k-1步，然后再一起走，直到p1为最后一个结点时，p2即为倒数第k个节点 
class Solution {
public:
    ListNode* FindKthToTail(ListNode* p, unsigned int k) {
		// 快指针先走
        auto p1=p;
		for(int i=0;i!=k;++i){
			if(!p1){return nullptr;}
			else{p1=p1->next;}
		}
		// 等当快指针到达最后一个结点时，慢指针所指就是倒数第k个结点
        while(p1){
            p1=p1->next;
            p=p->next;
        }
        return p;
    }
};

