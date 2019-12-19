# 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

# 方法1：短路原理。同cpp版本的方法1
class Solution:
    def __init__(self):
        self.sum = 0
    def Sum_Solution(self, n):
        # write code here
        def qiusum(n):
            self.sum += n
            n -= 1
            return n>0 and self.Sum_Solution(n)
          
        qiusum(n)
        return self.sum
        
# 方法2：直接递归（不能用if啊，这是错误答案）
class Solution:
    def Sum_Solution(self, n):
        # write code here
        if n==1:
            return 1
        else:
            return self.Sum_Solution(n-1) + n
            
