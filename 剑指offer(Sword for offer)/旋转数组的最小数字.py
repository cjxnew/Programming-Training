# -*- coding:utf-8 -*-

# 没啥好说的，就是简单的查找。这道题出的有问题。

class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if len(rotateArray) == 0:
            return 0
 
        ret = rotateArray[0]
        if len(rotateArray) == 1:
            return ret
 
        for i in range(1,len(rotateArray)):
            now = rotateArray[i]
            if now < ret:
                ret = now
                break
        return ret
