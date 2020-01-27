// 请实现两个函数，分别用来序列化和反序列化二叉树。
// 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
// 从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序
// 的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），
// 以 ！ 表示一个结点值的结束（value!）。
// 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// 方法：借鉴了网友的思路。
// （1）序列化二叉树：用前序遍历的方法，递归来实现。
// 注意递归我用string来保存序列化字符串，但是因为牛客网很不合适地限定了函数返回类型为char*，
// 所以我们需要将string转换为c风格字符串
// （2）根据序列重建二叉树：也是用递归的方法，利用char*的指针依次后移、前序遍历的思想来递归的。
class Solution {
public:
    char* Serialize(TreeNode *root) { // 由于牛客网很不合适地限定了函数返回类型为char*
        string treeStr;
		if(!root){return "#";}
		preOrder(root, treeStr);
		size_t sz = treeStr.size();
		char* treeStr_c = new char[sz+1]; // 所以我们需要将string转换为c风格字符串
		strcpy(treeStr_c, treeStr.c_str()); // 光使用c_str()是不行的，因为c_str()返回的是const char*
		return treeStr_c;
    }

	void preOrder(TreeNode* r, string& treeStr){
		if(r){
			treeStr += to_string(r->val);
			treeStr += '!';
			preOrder(r->left, treeStr);
			preOrder(r->right, treeStr);
		}else{
			treeStr += "#";
		}
	}

    TreeNode* Deserialize(char *str) {
		return deCode(str);
    }

	TreeNode* deCode(char* &str){ // str是一个引用，char*指针的引用。
		// 之所要用char*&，而不是char*，是因为这是个递归函数，用引用才能保证每次递归后指向字符串的指针会随着递归的进行而移动
		if(*str == '#'){
			++str;
			return nullptr; 
		}
		int num = 0; // 用num得到每个二叉树结点的值
		while(*str != '!'){
			num = num*10 + (*str - '0');
			++str;
		}
		++str; // 跳过'!'，来到下一个数字或#
		TreeNode* node = new TreeNode(num); // 创建当前结点
		node->left = deCode(str); // 以前序遍历的顺序，递归得到左右子树
		node->right = deCode(str);
		return node;
	}

};

