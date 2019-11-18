// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
// 例如，如果输入如下4 X 4矩阵：
// 1 2 3 4 
// 5 6 7 8 
// 9 10 11 12 
// 13 14 15 16
// 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

#include<iostream>
#include<vector>
using namespace std;

// 我的方法：每次剪切矩阵第一行元素，取完后将剩下的矩阵逆时针旋转90度，再取旋转后矩阵的第一行元素。。。直到矩阵为空
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ans;
		// 当matrix的size等于1，说明它只有一行数据了
		while(matrix.size() != 1){
			// 将第一行数据输入到ans中
			for(int j = 0; j < matrix[0].size(); ++j){
				ans.push_back(matrix[0][j]);
			}
			// 删除第一行数据
			matrix.erase(matrix.begin());
			// 逆时针旋转90度
			matrix = rotate90(matrix);
		}
		// 将最后一行数据输入到ans中
		for(int j = 0; j < matrix[0].size(); ++j){
			ans.push_back(matrix[0][j]);
		}
		return ans;
    }

	// 得到输入矩阵逆时针旋转90度的矩阵
	vector<vector<int> > rotate90(vector<vector<int> > m){
		vector<vector<int> > n;
		// 逆时针转90度，原矩阵的倒数第k列，等于旋转后矩阵的第k行
		for(int j = m[0].size() - 1; j >= 0; --j){ // j为列
			vector<int> r;
			for(int i = 0; i < m.size(); ++i){ // i为行
				r.push_back(m[i][j]);
			}
			n.push_back(r);
		}
		return n;
	}
};

// 方法2：网上的普遍方法，我觉得没我的好
/*
    思想，用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，往对角分别前进和后退一个单位。
    提交代码时，主要的问题出在没有控制好后两个for循环，需要加入条件判断，防止出现单行或者单列的情况。
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
         
        // 输入的二维数组非法，返回空的数组
        if (row == 0 || col == 0)  return res;
         
        // 定义四个关键变量，表示左上和右下的打印范围
        int left = 0, top = 0, right = col - 1, bottom = row - 1;
        while (left <= right && top <= bottom)
        {
            // left to right
            for (int i = left; i <= right; ++i)  res.push_back(matrix[top][i]);
            // top to bottom
            for (int i = top + 1; i <= bottom; ++i)  res.push_back(matrix[i][right]);
            // right to left
            if (top != bottom)
            for (int i = right - 1; i >= left; --i)  res.push_back(matrix[bottom][i]);
            // bottom to top
            if (left != right)
            for (int i = bottom - 1; i > top; --i)  res.push_back(matrix[i][left]);
            left++,top++,right--,bottom--;
        }
        return res;
    }
};
