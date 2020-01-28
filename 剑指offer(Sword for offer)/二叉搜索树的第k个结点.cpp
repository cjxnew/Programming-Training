// 给定一棵二叉搜索树，请找出其中的第k小的结点。

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// 方法1：我的方法：。
// 先用中序遍历，遍历排序二叉树，将得到按元素值升序排列的vector
// 然后返回第k个vector元素，就完事了
class Solution {
public:
    TreeNode* KthNode(TreeNode* root, int k){
		if(!root){return nullptr;}
		if(k < 1){return nullptr;}
		vector<TreeNode*> nodes;
		inOrder(root, nodes);
		if(k <= nodes.size()){
			return nodes[k-1];
		}else{
			return nullptr;
		}
    }

	void inOrder(TreeNode* node, vector<TreeNode*>& nodes){
		if(node){
			inOrder(node->left, nodes);
			nodes.push_back(node);
			inOrder(node->right, nodes);
		}
	}

};

// 方法2：网友的精简中序递归方法。
class Solution {
    int count = 0; // 给类数据成员赋初始值，这是c++11才支持的功能
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if(pRoot){ 
                TreeNode *ret = KthNode(pRoot->left, k);
                if(ret) return ret;
                if(++count == k) return pRoot;
                ret = KthNode(pRoot->right,k);
                if(ret) return ret;
        }
        return nullptr;
    }
};

