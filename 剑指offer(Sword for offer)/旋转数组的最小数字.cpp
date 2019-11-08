// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 这道题我就用现成的轮子来做

// 方法1：使用algorithm库的min_element函数
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        return *(min_element(rotateArray.begin(), rotateArray.end())); // 也可以写成min_element(begin(rotateArray), end(rotateArray))
    }
};

// 方法2：先使用algorithm库的sort函数，再返回第一个元素
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        sort(rotateArray.begin(), rotateArray.end());
		return rotateArray[0];
    }
};
