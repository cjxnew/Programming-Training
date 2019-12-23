'''
// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
// 数值为0或者字符串不是一个合法的数值则返回0
// 输入描述: 输入一个字符串,包括数字字母符号,可以为空
// 输出描述: 如果是合法的数值表达则返回该数字，否则返回0
'''

class Solution:
    def StrToInt(self, s):
        # write code here
        numlist=['0','1','2','3','4','5','6','7','8','9','+','-']
        sum=0
        label=1#正负数标记
        if s=='':
            return 0
        for string in s:
            if string in numlist:#如果是合法字符
                if string=='+':
                    label=1
                    continue
                if string=='-':
                    label=-1
                    continue
                else:
                    sum=sum*10+numlist.index(string)
            if string not in numlist:#非合法字符
                sum=0
                break#跳出循环
        return sum*label
        
        
