// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

#include<vector>
#include<iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

// 方法1：我的方法。
// 我用画图+归纳法，总结了三种情况。设输入结点为x，中序遍历的下一结点为y：
// （1）当x有右儿子：y为x的右子树的最左边结点
// （2）当x无右儿子：
//			a. x是x的父结点的左儿子：y为x的父结点
//			b. x是x的父结点的右儿子：
//									<1>若父结点是爷结点的左儿子：y为x的爷结点
//									<2>否则为NULL，到达树的中序遍历的末尾
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* x){
		if(!x){return nullptr;}
		// （1）当x有右儿子：y为x的右子树的最左边结点
		if(x->right){
			TreeLinkNode* leftSubtree = x->right;
			while(leftSubtree->left){
				leftSubtree = leftSubtree->left;
			}
			return leftSubtree;
		}
		// （2）当x无右儿子：
		else{
			TreeLinkNode* father = x->next;
			// 父结点为空，则x为树的头结点，且没有右子树，所以中序的下一结点为空
			if(!father){return nullptr;}
			// a. x是x的父结点的左儿子：y为x的父结点
			else if(father->left == x){
				return father;
			}
			// b. x是x的父结点的右儿子：
			else if(father->right == x){
				TreeLinkNode* grandpa = father->next;
				// 父结点是树的头结点时
				if(!grandpa){return nullptr;}
				// <1>若父结点是爷结点的左儿子：y为x的爷结点
				if(grandpa->left == father){
					return grandpa;
				}
				// <2>否则为NULL，到达树的中序遍历的末尾
				else{
					return nullptr;
				}
			}//else if
		}//else
    }//GetNext()
};


// 方法2：也是归纳法，但是比我简洁一点。
//分析二叉树的下一个节点，一共有以下情况：
//1.二叉树为空，则返回空；
//2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
//3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
//代码如下：
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        if(pNode->right!=NULL)
        {
            pNode=pNode->right;
            while(pNode->left!=NULL)
                pNode=pNode->left;
            return pNode;
        }  
        while(pNode->next!=NULL)
        {
            TreeLinkNode *proot=pNode->next;
            if(proot->left==pNode)
                return proot;
            pNode=pNode->next;
        }
        return NULL;
    }
};

