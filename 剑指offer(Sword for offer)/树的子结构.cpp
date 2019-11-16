// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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

// 我的方法：这样写是不能通过牛客网的测试用例的。
// 因为牛客网要求的是t2树是否是t1树的“子结构”，而非是否是t1树的子树！
// 我这样写，求得是t2树是否是t1树的子树
class Solution {
public:
    bool HasSubtree(TreeNode* t1, TreeNode* t2)
    {
		if(!t1 || !t2){return false;}
		if(isSameTree(t1, t2)){return true;}
		bool l = isSameTree(t1->left, t2);
		bool r = isSameTree(t1->right, t2);
		return l || r;
    }
	// 工具函数：判断两颗树是否相等
	// 用递归的方法，判断两颗树是不是相等
	bool isSameTree(TreeNode* tree1, TreeNode* tree2){
		if(!tree1 && !tree2){return true;}
		if(!tree1 || !tree2){return false;}
		if(tree1->val != tree2->val){return false;}
		bool l = isSameTree(tree1->left, tree2->left);
		bool r = isSameTree(tree1->right, tree2->right);
		return l && r;
	}
};

// 方法2：用DFS深度搜索遍历的方法，看t2树是否是t1树的某段子结构。
class Solution {
public:
	// 递归
    bool HasSubtree(TreeNode* t1, TreeNode* t2)
    {
		if(!t1 || !t2){return false;}
		return isPartTree(t1, t2) || HasSubtree(t1->left, t2) || HasSubtree(t1->right, t2);
    }
	// 工具函数：DFS判断一颗树是否是另一棵树的一段子结构
	bool isPartTree(TreeNode* tree1, TreeNode* tree2){
		if(!tree2){return true;} // 当tree2已经遍历完成了（为NULL了），说明tree2的每个结点在tree1中都有对应的结点了，返回true
		if(!tree1){return false;} // 当tree2不为空，而tree1为空，返回false
		if(tree1->val == tree2->val){ // 当tree1、2都不空，其元素相等时，递归
			return isPartTree(tree1->left, tree2->left) && isPartTree(tree1->right, tree2->right);
		}else{return false;} // 其元素不相等时，返回false
	}
};

