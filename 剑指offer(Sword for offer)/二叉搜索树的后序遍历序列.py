# -*- coding:utf-8 -*-

# 思路同cpp中的非递归版本
class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if len(sequence) == 0:
            return False
        root_index = len(sequence) - 1
        index = 0
        while root_index:
            while sequence[index] < sequence[-1]:
                index += 1
            while sequence[index] > sequence[-1]:
                index += 1
            if index < root_index:
                return False
            root_index -= 1
        return True
        
