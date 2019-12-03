 '''
 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
 但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
 '''
 
# 我的土办法。
# 先写一个统计整数n有几个1的函数countOne，再对1~n这n个整数都调用countOne，统计一共出现的1的次数
 class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        count = 0
        if n <= 0:
            return count
        for i in range(1, n+1):
            count += self.countOne(i)
        return count
        
    def countOne(self, n):
        count = 0
        while n != 0:
            if n % 10 == 1:
                count += 1
            n /= 10
            n = int(n) # 注意！python不像C++默认会强制类型转换，这个n除以10很可能变成浮点数了，所以这里我手动类型转换下
        return count
        
