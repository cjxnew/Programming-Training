// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.size()==0||vin.size()==0||pre.size()!=vin.size()){
			return NULL;
		}
		// 得到先序遍历序列的第一个元素（根节点），初始化根节点
		int head_elem = pre[0];
		TreeNode *node = new TreeNode(head_elem);
		// 初始化根节点左子树、右子树对应的先序遍历、中序遍历序列
		vector<int> left_pre, left_vin, right_pre, right_vin;

		// 找到根节点在中序遍历中的索引
		int vin_index = 0;
		for(int i = 0; i < vin.size(); ++i){
			if(vin[i] == head_elem){
				vin_index = i;
				break;
			}
		}
		// 得到根节点左子树、右子树对应的先序遍历、中序遍历序列
		for(int i = 0; i < vin_index; ++i){
			left_pre.push_back(pre[i+1]); // 这里得是i+1，因为第0索引是根节点！不懂可以画个图！
			left_vin.push_back(vin[i]);
		}
		for(int i = vin_index + 1; i < vin.size(); ++i){
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		// 递归
		node->left = reConstructBinaryTree(left_pre,left_vin);
		node->right = reConstructBinaryTree(right_pre,right_vin);
		return node;
    }
};
