// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

#include<vector>
#include<iostream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


// 方法1，我的方法。先中序遍历这棵树，得到升序排列的结点序列，再将这些结点的左右指针连起来
class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
		if(!root){return NULL;}
		vector<TreeNode*> inOrderNodeList;
		// 得到中序遍历（升序）的结点序列
		inOrderList(root, inOrderNodeList);
		// 连接这些结点的左右指针
		for(int i = 0; i < inOrderNodeList.size(); ++i){
			if(i != inOrderNodeList.size()-1){
				inOrderNodeList[i]->right = inOrderNodeList[i+1];
			}
			if(i != 0){
				inOrderNodeList[i]->left = inOrderNodeList[i-1];
			}
		}
		return inOrderNodeList[0];
    }

	// 中序遍历，将结点放入vector里
	void inOrderList(TreeNode* root, vector<TreeNode*>& list){
		if(root){
			inOrderList(root->left, list);
			list.push_back(root);
			inOrderList(root->right, list);
		}
	}
};
