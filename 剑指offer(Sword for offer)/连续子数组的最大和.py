 '''
 计算连续子向量的最大和。
 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
 [1,-2,3,10,-4,7,2,-5]，对应输出应该为:18，即3,10,-4,7,2。
 给一个数组，返回它的最大连续子序列的和
 '''
 # 思路同cpp里的，动态规划基础题
 '''
 正确方法：这题目应该是最基础的动态规划的题目。
 最大子数组的和一定是由当前元素和之前最大连续子数组的和叠加在一起形成的，
 因此需要遍历n个元素，看看当前元素和其之前的最大连续子数组的和能够创造新的最大值。

 令“最大连续子序列的和”称为X
 （1）创建一个和输入array长度一样的数组dp，保存每个位置的X
 （2）创建一个变量maxSum，保存当前全局的最大X
 （3）遍历输入数组的每个位置，每个位置的X，必定是前一个位置的X加上本位置的值、或前一个位置的X
 '''
 
 # 实现1
 class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        maxSum = array[0]
        dp = [0 for i in range(len(array))]
        dp[0] = array[0]
        for i in range(1, len(array)):
            curSum = dp[i-1] + array[i]
            if curSum > array[i]:
                dp[i] = curSum
            else:
                dp[i] == array[i]
            if dp[i] > maxSum:
                maxSum = dp[i]
        return maxSum
        
# 实现2
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        max_sum, cur_sum = -0xffffff, 0
        for i in array:
            if cur_sum <= 0:
                cur_sum = i
            else:
                cur_sum += i
            if cur_sum > max_sum:
                max_sum = cur_sum
        return max_sum
        
