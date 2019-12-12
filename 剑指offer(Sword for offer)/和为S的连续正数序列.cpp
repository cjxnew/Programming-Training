// 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
// 如：和为100的连续数组有，{9~16}、{18,19,20,21,22}

#include<vector>
#include<iostream>
#include<numeric> // 对数组的求和函数
using namespace std;


// 方法1：我的方法。用两个循环解决。
// 从1开始遍历到sum-1，依次将遍历到的连续正整数放到暂存数组seq中去
// （1）如果seq的元素之和等于目标sum，则将seq加入到最终的ans数组中，
// （2）如果seq的元素之和大于sum，说明这个序列不行，继续添加数字进去只会比sum越来越大
// 此时将seq的起始数字往后移一位，继续遍历
// （3）如果seq的元素之和小于sum，说明还需要继续添加数字到seq里去尝试
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > ans;
		if(sum < 3){return ans;}
		vector<int> seq;
		// i是seq的起始数字
		for(int i = 1; i < sum; ++i){
			for(int j = i; j < sum; ++j){
				seq.push_back(j);
				if(accumulate(seq.begin(), seq.end(), 0) < sum){
					continue;
				}else{
					if(accumulate(seq.begin(), seq.end(), 0) == sum){
						ans.push_back(seq);
					}
					seq.clear();
					break;
				}
			}//for j
		}//for i
		return ans;
	}
};

// 方法2：双指针思路。当总和小于sum，大指针继续+，否则小指针+
// 就是相当于有一个窗口，窗口的左右两边就是两个指针，我们根据窗口内值之和来确定窗口的位置和宽度。
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > allRes;
		// 两个起点，相当于动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
		int phigh = 2, plow = 1;
		while(phigh > plow){
			int cur = (phigh + plow) * (phigh - plow + 1) / 2; // 等差数列的求和公式：(a0+an)*n/2
			// 如果当前窗口内的值之和小于sum，那么右边窗口右移一下
			if(cur < sum){
				phigh++;
			}
			if(cur == sum){ // 相等，那么就将窗口范围的所有数添加进结果集
				vector<int> res;
				for(int i = plow; i<=phigh; i++){
					res.push_back(i);
				}
				allRes.push_back(res);
				plow++;
			}
			//如果当前窗口内的值之和大于sum，那么左边窗口右移一下
			if(cur > sum){
				plow++;
			}
		}
		return allRes;
	}
};

