// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) {}
};

// 方法1，我的方法。创建一个用于保存原链表-复制链表对应结点的字典
// 先遍历原链表，把next关系复制好。新建一个结点的同时，把原链表结点-复制链表结点键值对放到字典里
// 再遍历原链表，把random关系复制好。通过原链表-复制链表对应结点字典，找到random关系对应的结点
class Solution {
public:
	RandomListNode* Clone(RandomListNode* h)
	{
		if(!h){return NULL;}
		// 用于保存原链表-复制链表对应结点的字典
		map<RandomListNode*, RandomListNode*> node_address; // node_address的key保存原链表的结点地址，value保存复制后链表的结点地址
		RandomListNode* copyH = new RandomListNode(h->label);
		node_address.insert(pair<RandomListNode*, RandomListNode*>(h, copyH));
		RandomListNode* tmpH = h;
		RandomListNode* ansH = copyH;
		RandomListNode* toolH = copyH;
		// 先遍历原链表，把next关系复制好。新建一个结点的同时，把原链表结点-复制链表结点键值对放到字典里
		while(tmpH->next){
			RandomListNode* tmpNext = new RandomListNode(tmpH->next->label);
			copyH->next = tmpNext;
			node_address.insert(pair<RandomListNode*, RandomListNode*>(tmpH->next, copyH->next));
			tmpH = tmpH->next;
			copyH = copyH->next;
		}
		// 再遍历原链表，把random关系复制好。通过原链表-复制链表对应结点字典，找到random关系对应的结点
		while(h){
			if(!h->random){
				toolH->random = NULL;
			}else{
				toolH->random = node_address[h->random];
			}
			h = h->next;
			toolH = toolH->next;
		}
		return ansH;
	}
};

// 方法2. 感觉没我的简便
/*
*解题思路：
*1、遍历链表，复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面；
*2、重新遍历链表，复制老结点的随机指针给新结点，如A1.random = A.random.next;
*3、拆分链表，将链表拆分为原链表和复制后的链表
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return NULL;
    nodeClone(pHead);
    connectRandom(pHead);
    return reconnect(pHead);
    }
     
     
//[1]复制结点，插入到原结点后方
void nodeClone(RandomListNode *head)
{
    RandomListNode *pNode = head;
    while (pNode != NULL)
    {
        RandomListNode *pClone = new RandomListNode(pNode->label);
        pClone->next = pNode->next;
        pNode->next = pClone;
        pNode = pClone->next;
    }
}
 
//[2]还原新结点的random指针
void connectRandom(RandomListNode *head)
{
    RandomListNode *pNode = head;
     
    while (pNode != NULL)
    {
        RandomListNode *pClone = pNode->next;
        if (pNode->random)
        {
            pClone->random = pNode->random->next;
        }
        pNode = pClone->next;
    }
}
 
//[3]拆分
RandomListNode *reconnect(RandomListNode *head)
{
    RandomListNode *pNode = head;
    RandomListNode *result = head->next;
    while (pNode != NULL)
    {
        RandomListNode *pClone = pNode->next;
        pNode->next = pClone->next;
        pNode = pNode->next;
        if (pNode != NULL)
            pClone->next = pNode->next;
         
    }
    return result;
}
 
};

