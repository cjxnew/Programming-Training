# 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
# 如：和为100的连续数组有，{9~16}、{18,19,20,21,22}

# 方法1：思路同cpp中我的方法
'''用两个循环解决。
// 从1开始遍历到sum-1，依次将遍历到的连续正整数放到暂存数组seq中去
// （1）如果seq的元素之和等于目标sum，则将seq加入到最终的ans数组中，
// （2）如果seq的元素之和大于sum，说明这个序列不行，继续添加数字进去只会比sum越来越大
// 此时将seq的起始数字往后移一位，继续遍历
// （3）如果seq的元素之和小于sum，说明还需要继续添加数字到seq里去尝试'''
class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        res=[]
        for i in range(1,tsum/2+1):
            for j in range(i,tsum/2+2):
                tmp=(j+i)*(j-i+1)/2
                if tmp>tsum:
                    break
                elif tmp==tsum:
                    res.append(range(i,j+1))
        return res
        
# 方法2：双指针方法。
# 当总和小于sum，大指针继续+，否则小指针+
# 就是相当于有一个窗口，窗口的左右两边就是两个指针，我们根据窗口内值之和来确定窗口的位置和宽度。
class Solution:
    def FindContinuousSequence(self, tsum):
        if tsum < 3:
            return []
        small = 1
        big = 2
        middle = (tsum + 1)>>1
        curSum = small + big
        output = []
        while small < middle:
            if curSum == tsum:
                output.append(range(small, big+1))
                big += 1
                curSum += big
            elif curSum > tsum:
                curSum -= small
                small += 1
            else:
                big += 1
                curSum += big
        return output
        
