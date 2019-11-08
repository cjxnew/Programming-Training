# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        if array == [] or array[0] == []:
            return False
        for a_row in array:
            if target >= a_row[0] and target <= a_row[-1]:
                if target in a_row:
                    return True
        return False
