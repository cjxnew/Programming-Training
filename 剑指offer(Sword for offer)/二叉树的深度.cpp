// 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
// 形成树的一条路径，最长路径的长度为树的深度。

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

// 方法1，我的方法。利用二叉树的深度优先搜索来求。其实就是深度优先搜索求二叉树路径的代码改的
// 利用DFS方法找到树的所有路径的方法，找到最长的路径长度，就是树的深度
class Solution {
public:
    int TreeDepth(TreeNode* r)
    {
		if(!r){return 0;}
		int count = 0, maxCount = 0; // count用于统计每条路径的长度，maxCount保存最长的路径长度
		findMaxRoad(r, count, maxCount);
		return maxCount;
    }

	// DFS寻找二叉树所有路径的标准写法
	void findMaxRoad(TreeNode *data, int count, int& maxCount){
		++count;
		if(!data->left && !data->right){
			maxCount = count > maxCount ? count : maxCount;
			count = 0;
		}
		if(data->left){
			findMaxRoad(data->left, count, maxCount);}
		if(data->right){
			findMaxRoad(data->right, count, maxCount);} 
	}
};


// 方法2：极简递归方法。
class Solution {
public:
    int TreeDepth(TreeNode* r){
        if(!r) return 0;
        return max(1+TreeDepth(r->left), 1+TreeDepth(r->right));
    }
};
