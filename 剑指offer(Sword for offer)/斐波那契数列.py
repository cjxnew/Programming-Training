# -*- coding:utf-8 -*-
# 方法1
class Solution:
    def Fibonacci(self, n):
        # write code here
		if n == 0:
			return 0
		if n == 1:
			return 1
		return self.Fibonacci(n - 1) + self.Fibonacci(n - 2)

# 方法2
class Solution:
    def Fibonacci(self, n):
        # write code here
  if n < 2:
   return n
        a, b = 0, 1
        result = 0
        for i in range(2, n+1):
            result = a + b
            a = b
            b = result
  return result
