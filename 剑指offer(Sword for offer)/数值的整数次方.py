# -*- coding:utf-8 -*-

# 方法1：直接调用pow()
class Solution:
    def Power(self, base, exponent):
        # write code here
		return pow(base, exponent)

# 方法2：同本题cpp版本里的方法1
class Solution:
    def Power(self, base, exponent):
        # write code here
		if exponent == 0:
			return 1.
		index = abs(exponent)
		result = base if exponent > 0 else 1./base
		b = result
		while index > 1:
			result *= b
			index -= 1
		return result
    
