// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
// 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
// 他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
// {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

#include<vector>
using namespace std;


// 方法1：我的方法。一刷22mins，难度较简单
// 使用vector的迭代器，来求每个“滑动窗口”的最大值
// 已经数组的长度为len，滑动窗口的长度为sz，则一共可以取到len-sz+1个滑动窗口。
// 首先令两个迭代器temp_beg和temp_end分别指向第一个滑动窗口的首元素和尾后位置，并求这个滑动窗口的最大值
// 然后进行len-sz+1次循环，每次循环都递增temp_beg和temp_end，求对应滑动窗口的最大值。
// 就完事了。
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& nums, unsigned int sz){
		if(nums.size() <= 1){return nums;}
		vector<int> ans;
		if(sz > nums.size() || sz < 1){return ans;}
		if(sz == nums.size()){
			ans.push_back(maxValue(nums));
			return ans;
		}
		unsigned int count = nums.size() - sz + 1;
		auto temp_beg = nums.begin();
		auto temp_end = temp_beg + sz;
		while(count > 0){
			vector<int> temp(temp_beg, temp_end);
			ans.push_back(maxValue(temp));
			++temp_beg;
			++temp_end;
			--count;
		}
		return ans;
    }
	
	// 求最大值的工具函数
	int maxValue(const vector<int>& vec){
		auto beg = vec.begin();
		auto end = vec.end();
		int maxNum = *beg;
		while(beg != end){
			if(*beg > maxNum){
				maxNum = *beg;
			}
			++beg;
		}
		return maxNum;
	}

};


// 方法2：网友的方法。利用下标运算来求。
class Solution {
public:
    int findMax(const vector<int>& num,int index,int size){
        int max=num[index];
        for(int i=index-1;i>=index-size+1;i--){
            if(max<num[i])max=num[i];
        }
        return max;
    }
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {  
        vector<int> vec;
        for(int i=size-1;i<num.size();i++)
            vec.push_back(findMax(num,i,size));
        return vec;
    }
};

