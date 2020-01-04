// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

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


// 方法1：我的方法。
// 首先，认为从左到右打印是顺序打印，从右到左是逆序打印。
// （1）先层次遍历整个树，将遍历的数据依次保存在一个vector里，vector里同时保存了每一层数据是否要逆序打印
// （2）再遍历vector，将顺序打印的数字和逆序打印的数字一层层push到vector<vector<int> > ans里
// （这道题我花了很多时间，主要是因为一个小小的超出vector范围的问题，调试了很久，也就是第二个while循环里，i应该 < elems.size()-1，而非elems.size()）
class Solution {
public:
	vector<vector<int> > Print(TreeNode* r) {
		vector<vector<int> > ans;
		if(!r){return ans;}
		vector<pair<TreeNode*, bool> > elems = getElems(r);
		int i = 0;
		while(i < elems.size()){
			vector<int> row;
			row.push_back(elems[i].first->val);
			while(i < elems.size()-1 && elems[i+1].second == elems[i].second){
				++i;
				row.push_back(elems[i].first->val);
			}
			if(elems[i].second == true){reverse(row.begin(), row.end());}
			ans.push_back(row);
			++i;
		}
		return ans;
	}

	// 得到层次遍历的二叉树元素队列。每个元素都对应一个布尔值，代表是否是逆序行。
	vector<pair<TreeNode*, bool> > getElems(TreeNode* r){
		queue<pair<TreeNode*, bool> > Q;
		vector<pair<TreeNode*, bool> > elems;
		TreeNode* head = r;
		Q.push(pair<TreeNode*, bool>(head, false));
		while(!Q.empty()){
			pair<TreeNode*, bool> p = Q.front();
			elems.push_back(p);
			Q.pop();
			if(p.first->left){
				Q.push(pair<TreeNode*, bool>(p.first->left, !(p.second)));
			}
			if(p.first->right){
				Q.push(pair<TreeNode*, bool>(p.first->right, !(p.second)));
			}
		}
		return elems;
	}
};

// 方法2：牛客网友的做法，是我的思路的精简版！很好！
// 也是利用层次遍历的思路。树的每一层结点，都用一个for循环处理完。
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL)
            return res;
        queue<TreeNode*> que;
        que.push(pRoot);
        bool even = false;
        while(!que.empty()){
            vector<int> vec;
            const int size = que.size();
            for(int i=0; i<size; ++i){ // size保存的是某一层结点的个数
                TreeNode* tmp = que.front();
                que.pop();
                vec.push_back(tmp->val);
                if(tmp->left != NULL)
                    que.push(tmp->left);
                if(tmp->right != NULL)
                    que.push(tmp->right);
            }
            if(even) // even为真则逆置
                std::reverse(vec.begin(), vec.end());
            res.push_back(vec);
            even = !even;
        }
        return res;
    }
     
};

