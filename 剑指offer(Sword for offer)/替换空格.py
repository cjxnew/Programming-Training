# 方法1：将字符串转变为list，插值后再转换回去
# -*- coding:utf-8 -*-
class Solution:
   # s 源字符串
   def replaceSpace(self, s):
       # write code here
       s = list(s)
       count=len(s)
       for i in range(0,count):
           if s[i]==' ':
               s[i]='%20'
       return ''.join(s) # ''.join(s)意思是将列表s转换为字符串，原来的列表元素在变为字符串后，用''分隔


# 方法2：用字符串函数replace
# -*- coding:utf-8 -*-
class Solution:
   # s 源字符串
   def replaceSpace(self, s):
       return s.replace(" ", "%20")
