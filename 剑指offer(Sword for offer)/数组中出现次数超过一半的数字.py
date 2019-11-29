# 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组
# {1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

# 方法1：我的方法。
# 依次判断数组前一半的数字是不是出现次数超过一半的数字
# 对每个判断的数字x，定义一个计数器count，遍历整个数组。
# 当遍历到一个等于x的数字，计数器+1，不等于x，计数器-1，当遍历完数组，计数器>0，则x出现次数超过一半
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        if len(numbers) == 0:
            return 0
        # write code here
        for i in range(len(numbers)/2 + 1):
            count = 0
            for num_compare in numbers:
                if num_compare == numbers[i]:
                    count += 1
                else:
                    count -= 1
            if count > 0:
                return numbers[i]
        return 0
        
# 方法2，用字典统计每个元素的次数
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        dict = {}
        for no in numbers:
            if no not in dict.keys():
                dict[no] = 1
            else:
                dict[no] += 1
            if dict[no] > len(numbers)/2:
                return no
        return 0
        
# 方法3，调用Counter函数，其定义在collections库里
# Counter函数返回一个字典，包含每个元素出现的次数
import collections
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        tmp = collections.Counter(numbers)
        x = len(numbers)/2
        for k, v in tmp.items():
            if v > x:
                return k
        return 0
        
