// 请实现一个函数，用来判断一颗二叉树是不是对称的。
// 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

#include<iostream>
#include<stack>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


// 方法1：我的方法。子函数比较多，运用二叉树的知识比较综合。
// 分步解决：
// （1）先将原树r拷贝一份，称其为newr
// （2）再将拷贝版newr转化为镜像二叉树
// （3）最后比较镜像二叉树和原树r是否相等
class Solution {
public:
	bool isSymmetrical(TreeNode* r){
		if(!r){return true;}
		if(!r->left && !r->right){return true;}
		if(!r->left || !r->right){return false;}
		// 将原树拷贝一份
		TreeNode *newr;
		copyTree(r, newr);
		// 将拷贝版转化为镜像二叉树
		beMirrorTree(newr);
		// 比较镜像二叉树和原树是否相等
		return isEqualTree(r, newr);
	}

	// 拷贝二叉树r到c
	void copyTree(TreeNode* r, TreeNode*& c){
		if(!r){c = nullptr;return;}
		c = new TreeNode(0);
		c->val = r->val;
		copyTree(r->left, c->left);
		copyTree(r->right, c->right);
	}

	// 比较两棵树是否相等
	bool isEqualTree(TreeNode* r, TreeNode* t){
		if(!r && !t){return true;}
		if(!r || !t){return false;}
		if(r->val != t->val){return false;}
		else{
			return isEqualTree(r->left, t->left) && isEqualTree(r->right, t->right);
		}
	}

	// 将二叉树转变为自己的镜像树
	void beMirrorTree(TreeNode* r){
		if(!r || (!r->left && !r->right)){return;}
		TreeNode* tmp;
		tmp = r->left;
		r->left = r->right;
		r->right = tmp;
		beMirrorTree(r->left);
		beMirrorTree(r->right);
	}
};

// 方法2：极简递归方法。看来二叉树的问题，基本都能有递归解决办法呢。

/*思路：首先根节点以及其左右子树，左子树的左子树和右子树的右子树相同
* 左子树的右子树和右子树的左子树相同即可，采用递归
* 非递归也可，采用栈或队列存取各级子树根节点
*/
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot,pRoot);
	}
	bool isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2)
	{
		if(pRoot1==nullptr&&pRoot2==nullptr)
			return true;
		if(pRoot1==nullptr||pRoot2==nullptr)
			return false;
		if(pRoot1->val!=pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left,pRoot2->right)&& isSymmetrical(pRoot1->right,pRoot2->left);
	}

};

// 方法3：非递归算法，使用DFS，用栈来保存成对结点
/*
* DFS使用stack来保存成对的节点
* 1.出栈的时候也是成对成对的 ，
1.若都为空，继续；
2.一个为空，返回false;
3.不为空，比较当前值，值不等，返回false；
* 2.确定入栈顺序，每次入栈都是成对成对的，如left.left， right.right ;left.rigth,right.left
*/
bool isSymmetricalDFS(TreeNode* pRoot){
	if(!pRoot){return true;}
	stack<TreeNode*> s;
	s.push(pRoot->left);
	s.push(pRoot->right);
	while(!s.empty()) {
		TreeNode* right = s.top();//成对取出
		s.pop();
		TreeNode* left = s.top();
		s.pop();
		if(!left && !right){continue;}
		if(!left || !right){return false;}
		if(left->val != right->val){return false;}
		//成对插入
		s.push(left->left);
		s.push(right->right);
		s.push(left->right);
		s.push(right->left);
	}
	return true;
}

// 方法4：非递归算法，使用BFS，用队列来保存成对结点
/*
* BFS使用Queue来保存成对的节点，代码和上面极其相似
* 1.出队的时候也是成对成对的
1.若都为空，继续；
2.一个为空，返回false;
3.不为空，比较当前值，值不等，返回false；
* 2.确定入队顺序，每次入队都是成对成对的，如left.left， right.right ;left.rigth,right.left
*/
bool isSymmetricalBFS(TreeNode* pRoot)
{
	if(!pRoot){return true;}
	queue<TreeNode*> s;
	s.push(pRoot->left);
	s.push(pRoot->right);
	while(!s.empty()) {
		TreeNode* left = s.front();//成对取出
		s.pop();
		TreeNode* right = s.front();
		s.pop();
		if(!left && !right){continue;}
		if(!left || !right){return false;}
		if(left->val != right->val){return false;}
		//成对插入
		s.push(left->left);
		s.push(right->right);
		s.push(left->right);
		s.push(right->left);
	}
	return true;
}

