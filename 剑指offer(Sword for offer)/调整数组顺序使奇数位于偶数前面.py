# -*- coding:utf-8 -*-
# 用冒泡排序，前偶后奇则交换位置
class Solution:
    def reOrderArray(self, array):
        # write code here
        for i in range(len(array)):
            for j in range(len(array)-1,i,-1):
                if array[j-1]%2 ==0 and array[j]%2==1:
                    array[j-1], array[j] = array[j], array[j-1]
        return array
