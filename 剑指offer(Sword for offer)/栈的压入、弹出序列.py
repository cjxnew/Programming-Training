# -*- coding:utf-8 -*-

# 方法1：我的方法。直接遍历两个序列，用一个栈来模拟这个入栈、出栈的过程
class Solution:
    def IsPopOrder(self, pu, po):
        # write code here
        stack = []
        puIndex = poIndex = 0
        while poIndex < len(po):
            if puIndex < len(pu):
                stack.append(pu[puIndex])
                puIndex += 1
            while len(stack) > 0 and stack[-1] == po[poIndex]:
                stack.pop()
                poIndex += 1
                if poIndex == len(po):
                    break
            if puIndex == len(pu) and len(stack) != 0:
                return False
        return True
