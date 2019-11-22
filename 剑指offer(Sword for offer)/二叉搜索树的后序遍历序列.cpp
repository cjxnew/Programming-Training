// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

// 要注意！题目说的是这个序列有没有可能是某二叉搜索树的后序遍历序列
// 由于只有后序序列，对应的树自然不唯一，但只要能根据该序列画出一个二叉搜索树就行

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 方法1：递归做法。
// 后序序列最后一个值为root；二叉搜索树左子树值都比root小，右子树值都比root大。
// 1、确定root；
// 2、遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
// 3、遍历右子树，若发现有小于root的值，则直接返回false；
// 4、分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）。
//class Solution {
//public:
//    bool VerifySquenceOfBST(vector<int> sequence) {
//        vector<int> leftTree,rightTree;
//        int root; // 根结点
//        if(sequence.empty()) return false;
//        int index = 0; // 标记左右子树界限
//        int len = sequence.size();
//        root = sequence[len-1];
//        int i=0;
//        for(;i<len-1;++i)
//        {
//            if(sequence[i]>root) break; // 找到第一个大于根结点的位置，则左边为左子树，右边为右子树
//        }
//        for(int j=i;j<len-1;++j) // 循环时去除root，因此为len-1
//        {
//            if(sequence[j]<root) return false; // 有一个小于root，则返回false
//        }
//        // 即有左子树
//        if(i!=0)
//        {
//            for(int m=0;m<i;++m)
//            {
//                leftTree.push_back(sequence[m]);
//            }
//        }
//		// 即有右子树
//        if(i!=len-2)
//        {
//            for(int j=i;j<len-1;++j)
//            {
//                rightTree.push_back(sequence[j]);
//            }
//        }
//         
//        bool left = true,right = true; // 看左右子树是否是二叉搜索树
//        if(leftTree.size()>1) VerifySquenceOfBST(leftTree);
//        if(rightTree.size()>1) VerifySquenceOfBST(rightTree);
//        return (left&&right);
//    }
//};

// 方法2：非递归。
//非递归 
//非递归也是一个基于递归的思想：
//左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
//最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
//即可，即使到达了左子树左子树也可以看出由左右子树组成的树还想右子树那样处理
//对于左子树回到了原问题，对于右子树，左子树的所有值都比右子树的根小可以暂时把他看出右子树的左子树
//只需看看右子树的右子树是否符合要求即可
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(0==size)return false;
 
        int i = 0;
        while(--size)
        {
            while(sequence[i++]<sequence[size]);
            while(sequence[i++]>sequence[size]);
 
            if(i<size)return false;
            i=0;
        }
        return true;
    }
};

