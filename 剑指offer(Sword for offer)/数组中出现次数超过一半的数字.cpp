// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组
// {1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include<vector>
#include<iostream>
using namespace std;

// 方法1：我的方法。
// 依次判断数组前一半的数字是不是出现次数超过一半的数字
// 对每个判断的数字x，定义一个计数器count，遍历整个数组。
// 当遍历到一个等于x的数字，计数器+1，不等于x，计数器-1，当遍历完数组，计数器>0，则x出现次数超过一半
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		if(numbers.size() == 0){return 0;}
		// 依次判断数组前一半的数字numbers[i]
		for(int i = 0; i < numbers.size()/2 + 1; ++i){
			int count = 0;
			// 定义一个计数器count，遍历整个数组
			for(int j = 0; j < numbers.size(); ++j){
				if(numbers[j] == numbers[i]){
					++count;
				}else{
					--count;
				}
			}
			// 当遍历完数组，计数器>0，则x出现次数超过一半
			if(count > 0){return numbers[i];}
		}
		return 0;
    }
};

// 方法2，网友的方法，感觉不如我的呀。
// 数组排序后，如果符合条件的数存在，则一定是数组中间那个数。（比如：1，2，2，2，3；或2，2，2，3，4；或2，3，4，4，4等等）
// 这种方法虽然容易理解，但由于涉及到快排sort，其时间复杂度为O(NlogN)并非最优
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if(numbers.empty()) return 0;
         
        sort(numbers.begin(),numbers.end()); // 排序，取数组中间那个数
        int middle = numbers[numbers.size()/2];
         
        int count=0; // 出现次数
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==middle) ++count;
        }
         
        return (count>numbers.size()/2) ? middle :  0;
    }
};

