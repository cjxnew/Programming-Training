#include <iostream>
#include <vector>
#include <stdio.h>
#include <numeric>
#include <algorithm>
using namespace std;

struct TreeNode{
 int val;
 TreeNode* left;
 TreeNode* right;
 TreeNode(int v):
 val(v),left(NULL),right(NULL){}
}; 

// 方法1：我的方法。先用深度搜索的方法，找出树的所有路径，保存到数组中
// 再遍历所有路径，找出符合要求的路径放到另一个数组中
// 再使用algorithm库的自定义sort函数，对其进行排序，将长度较大的路径放前面

// 自定义的sort排序规则，按路径长度降序排列
bool compare(vector<int> v1, vector<int> v2)
{
 return v1.size() > v2.size();
}

class Solution {
public:
  vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int> > ansP;
    if(!root){return ansP;}
    vector<vector<int> > allP;
    vector<int> p;
    savePaths(root, p, allP);
    for(vector<vector<int> >::iterator ap = allP.begin(); ap != allP.end(); ++ap){
     int sum_ = accumulate((*ap).begin(), (*ap).end(), 0);
     if(sum_ == expectNumber){
      ansP.push_back(*ap);
     }
    }
    sort(ansP.begin(), ansP.end(), compare);
    return ansP;
 }
 
 // 找出树的所有路径，放到数组中
 void savePaths(TreeNode *data,vector<int> path,vector<vector<int> >& allPath){
    path.push_back(data->val);
    if(data->left==NULL && data->right==NULL)
    {
     allPath.push_back(path);
    }
    if(data->left!=NULL)
     savePaths(data->left,path,allPath);
    if(data->right!=NULL)
     savePaths(data->right,path,allPath); 
   }
};

// 方法2. 通过每次更新expectNumber的值来递归求解
class Solution {
public:
    vector<vector<int> > buffer;
    vector<int> tmp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return buffer;
        tmp.push_back(root->val);
        if((expectNumber-root->val)==0 && root->left==NULL && root->right==NULL)
            {
            buffer.push_back(tmp);
        }
        FindPath(root->left,expectNumber-root->val);
        FindPath(root->right,expectNumber-root->val);
        if(tmp.size()!=0)
            tmp.pop_back();
        return buffer;
    }
};

// 方法3.思路和我的方法相仿。见本题python版本答案



// 测试用例
int main() {
 TreeNode* node1 = new TreeNode(1);
 TreeNode* node2 = new TreeNode(2);
 TreeNode* node3 = new TreeNode(3);
 TreeNode* node4 = new TreeNode(4);
 TreeNode* node5 = new TreeNode(5);
 TreeNode* node6 = new TreeNode(4);
 TreeNode* node7 = new TreeNode(7);
 TreeNode* node8 = new TreeNode(1);
 node1->left = node2;
 node1->right = node3;
 node2->left = node5;
 node2->right = node4;
 node3->left = node6;
 node3->right = node7;
 node4->left = node8;
 
 Solution s;
 vector<vector<int> > ansP;
 ansP = s.FindPath(node1, 8);
 for(vector<vector<int> >::iterator ap = ansP.begin(); ap != ansP.end(); ++ap){
  for(int i = 0; i < (*ap).size(); ++i){
   cout << (*ap)[i] << ' ';
  }
  cout << endl;
 }
 
 return 0;
}

