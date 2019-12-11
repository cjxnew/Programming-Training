// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。

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

// 牛客网这题有问题，二叉树只要符合“平衡”，就能通过题目。
// 但实际上二叉平衡树首先必须是二叉排序树

// 方法1（通过牛客测试）：我的方法。
// 利用递归思想，首先空树是二叉平衡树
// 平衡二叉树左子树高度和右子树高度之差不大于1
// 平衡二叉树的左右子树也是平衡二叉树，以此递归
class Solution {
public:
  bool IsBalanced_Solution(TreeNode* r) {
    if(!r){return true;}
    if(abs(TreeDeep(r->left) - TreeDeep(r->right)) > 1){return false;}
    return IsBalanced_Solution(r->left) && IsBalanced_Solution(r->right);
  }

	// 求树的深度
	int TreeDeep(TreeNode* r){
		if(!r){return 0;}
		return max(1+TreeDeep(r->left), 1+TreeDeep(r->right));
	}
};


// 方法1（严格解）：我的方法。
// 首先空树是二叉平衡树
// 二叉树首先必须是排序树，其次平衡二叉树左子树高度和右子树高度之差不大于1
// 平衡二叉树的左右子树也是平衡二叉树，以此递归
class Solution {
public:
  bool IsBalanced_Solution(TreeNode* r) {
    if(!r){return true;}
    if(!isBST(r)){return false;}
    if(abs(TreeDeep(r->left) - TreeDeep(r->right)) > 1){return false;}
    return IsBalanced_Solution(r->left) && IsBalanced_Solution(r->right);
  }

	// 求树的深度
	int TreeDeep(TreeNode* r){
		if(!r){return 0;}
		return max(1+TreeDeep(r->left), 1+TreeDeep(r->right));
	}


  // 判断一棵树是否是二叉排序树
  bool isBST(TreeNode* r){
    if(!r){return true;}
    if(r->left){
      if(r->left->val >= r->val){return false;}
    }
    if(r->right){
      if(r->right->val <= r->val){return false;}
    }
    return isBST(r->left) && isBST(r->right);
  }
  
};

