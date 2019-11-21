// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#include<iostream>
#include<vector>
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

// 我的方法：这是层次遍历二叉树的标准写法
// 借助一个队列，保存二叉树的结点
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		if(root){
		queue<TreeNode*> q; // 保存结点指针的队列
		vector<int> ans;
		q.push(root); // 先将根节点入队
		while(!q.empty()){
			TreeNode* node = q.front(); // 取队列的首结点
			q.pop(); // 首节点出队
			ans.push_back(node->val); // 将首节点的值取到
			if(node->left){ // 若存在左子结点，将其入队
				q.push(node->left);
			}
			if(node->right){ // 若存在右子结点，将其入队
				q.push(node->right);
			}
		}
		return ans;
	}
	}
};

// 上面写的明明是对的。。但是还是不能通过牛客的例子。。。就因为当root为空时必须返回一个空vector。。真是有病
// 下面这样写就可以通过。。。
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(root){
            queue<TreeNode*> q; // 保存结点指针的队列
            q.push(root); // 先将根节点入队
            TreeNode* node;
            while(!q.empty()){
                node = q.front(); // 取队列的首结点
                q.pop(); // 首节点出队
                ans.push_back(node->val); // 将首节点的值取到
                if(node->left){ // 若存在左子结点，将其入队
                    q.push(node->left);
                }
                if(node->right){ // 若存在右子结点，将其入队
                    q.push(node->right);
                }
            }
            return ans;
        }else{return ans;}
    }
};

