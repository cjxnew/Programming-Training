'''输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。'''

# 我的方法。
# 先用全排列itertools.permutations函数进行全排列
# 再用str()和int()函数进行类型转换，找出最小的数
class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        allPossibleNum = []
        if len(numbers) == 0:
            return allPossibleNum
        # 所有可能的数字组合
        allPossibleNum = self.fun(numbers)
        # 将数字组合转化为数字，找到最小的那个数字
        minNum = 99999999
        for numList in allPossibleNum:
            numStr = ''
            for num in numList:
                numStr += str(num)
            if minNum > int(numStr):
                minNum = int(numStr)
        return str(minNum)
        
    # 全排列函数
    def fun(self, numbers):
        return list(itertools.permutations(numbers))
        
