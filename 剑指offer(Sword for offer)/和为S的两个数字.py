# 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
# 如果有多对数字的和等于S，输出两个数的乘积最小的。

# 方法：网友的方法，暴力搜索吧。
# 感觉还不如cpp版本里我的方法好，起码我用了折半查找
class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # write code here
        ls = []
        if not isinstance(array, list):
            return ls
        for i, v in enumerate(array):
            for v1 in array[i:]:
                if (v + v1) == tsum:
                    ls.append([v, v1])
        if ls:
            return ls[0]
        else:
            return ls
            
