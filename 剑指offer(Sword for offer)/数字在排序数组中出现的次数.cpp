// 统计一个数字在排序数组中出现的次数。

#include<vector>
#include<algorithm> // lower_bound()、upper_bound()
using namespace std;

// 方法1：我的方法。暴力搜索，时间复杂度O(n)。
// 怎么会出这么简单的题目？？？
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
		if(data.size() == 0){return 0;}
        int count = 0;
		for(auto e : data){
			if(e == k){++count;}
		}
		return count;
    }
};

// 方法2：因为有序，所以折半查找。
// 用STL库algorithm来做，时间复杂度O(logn)
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto l = lower_bound(data.begin(), data.end(), k);
        auto r = upper_bound(data.begin(), data.end(), k);
        return r - l;
    }
};
