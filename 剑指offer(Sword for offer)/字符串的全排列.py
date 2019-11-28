# 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
# 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
# 输入描述: 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

# 方法1：我按全排序问题的标准写法来做的
class Solution:
    def Permutation(self, ss):
        all_str = []
        if len(ss) == 0:
            return all_str
        s = list(ss) # 注意在python中字符串和tuple一样是不可改变对象，为了交换元素我先把其转换为列表
        self.fun(s, 0, all_str)
        return sorted(all_str)
        
    def fun(self, s, begin, all_str):
        if begin == len(s)-1:
            ss = ''.join(s)
            if ss not in all_str:
                all_str.append(ss)
        else:
            for i in range(begin, len(s)):
                s[i], s[begin] = s[begin], s[i]
                self.fun(s, begin+1, all_str)
                s[i], s[begin] = s[begin], s[i]
                
# 方法2：网友的神奇解法，调用了itertools这个库
import itertools
class Solution:
    def Permutation(self, ss):
        # write code here
        if not ss:
            return []
        return sorted(list(set(map(''.join, itertools.permutations(ss)))))
        
