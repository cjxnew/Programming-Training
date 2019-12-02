// 计算连续子向量的最大和。
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// [1,-2,3,10,-4,7,2,-5]，对应输出应该为:18，即3,10,-4,7,2。
// 给一个数组，返回它的最大连续子序列的和

#include<vector>
#include<iostream>
#include<numeric> // accumulate，输入数组范围、加和起始索引，返回累加值
#include<algorithm> // max_element 输入数组范围，返回指向最大元素的迭代器
using namespace std;

// 我的方法：错误方法。这道题不是简单的累加求和，而是动态规划！最基础的动态规划题！
//class Solution {
//public:
//    int FindGreatestSumOfSubArray(vector<int> array) {
//		if(array.size() == 0){return 0;}
//		vector<int> partSum;
//		vector<int> partArray;
//		for(auto i : array){
//			partArray.push_back(i);
//			int sum = accumulate(partArray.begin(), partArray.end(), 0);
//			partSum.push_back(sum);
//		}
//		return *max_element(partSum.begin(), partSum.end());
//    }
//};

// 正确方法1：这题目应该是最基础的动态规划的题目。
// 最大子数组的和一定是由当前元素和之前最大连续子数组的和叠加在一起形成的，
// 因此需要遍历n个元素，看看当前元素和其之前的最大连续子数组的和能够创造新的最大值。

// 令“最大连续子序列的和”称为X
// （1）创建一个和输入array长度一样的数组dp，保存每个位置的X
// （2）创建一个变量maxSum，保存当前全局的最大X
// （3）遍历输入数组的每个位置，每个位置的X，必定是前一个位置的X加上本位置的值、或前一个位置的X
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
		if(array.size() == 0){return 0;}
		vector<int> dp;
		int maxSum = array[0];
		dp.push_back(array[0]);
		for(int i = 1; i < array.size(); ++i){
			int curSum = dp[i-1] + array[i];
			if(curSum > array[i]){ // 注意这里是curSum>array[i]，而不是curSum>dp[i-1]
				dp.push_back(curSum);
			}else{ // 即，若dp[i-1]是负数，则dp[i]=array[i]，否则dp[i]=dp[i-1]+array[i]
				dp.push_back(array[i]);
			}
			if(dp[i] > maxSum){
				maxSum = dp[i];
			}
		}
		return maxSum;
    }
};

// 正确方法2：更快的实现办法
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
         
        int cursum=array[0];
        int maxsum=array[0];
        for(int i=1;i<array.size();i++){
            cursum+=array[i];
            if(cursum<array[i])
                cursum=array[i];
            if(cursum>maxsum)
                maxsum=cursum;           
        }
    return maxsum;
    }
};

