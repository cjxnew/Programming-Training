// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

#include<vector>

// 方法1：我的土方法。
class Solution {
public:
    void reOrderArray(vector<int> &array) {
		// 定义两个vector，分别按顺序存放奇数、偶数
        vector<int> even_elems;
		vector<int> odd_elems;
		// 把奇数、偶数放到对应的vector里
		for(int i = 0; i < array.size(); ++i){
			if(even(array[i])){even_elems.push_back(array[i]);}
			else{odd_elems.push_back(array[i]);}
		}
		// 将奇数、偶数再按题目要求的顺序存回array里
		for(int i = 0; i < odd_elems.size(); ++i){
			array[i] = odd_elems[i];
		}
		for(int i = odd_elems.size(); i < array.size(); ++i){
			array[i] = even_elems[i - odd_elems.size()];
		}
    }
	// 判断一个整数是否是偶数
	bool even(int n){
		if(abs(n) % 2 == 0){return true;}
		else{return false;}
	}
};

// 方法2：网友的土方法
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> result;
        int num=array.size();
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==1)
                result.push_back(array[i]);
        }
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==0)
                result.push_back(array[i]);
        }
        array=result;
    }
};

// 方法3：用冒泡排序（冒泡排序是稳定的，所以可以保证元素相对位置不变），前偶后奇数就交换：
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for (int i = 0; i < array.size();i++)
        {
            for (int j = array.size() - 1; j>i;j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //前偶后奇交换
                {
                    swap(array[j], array[j-1]);
                }
            }
        }
    }
};
