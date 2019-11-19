# -*- coding:utf-8 -*-

# 我的方法
class Solution:
    c = [] # 容器
    min_elem = 99999
    sec_min_elem = 99999
    def push(self, node):
        self.c.append(node)
        if node < self.min_elem:
            self.sec_min_elem = self.min_elem
            self.min_elem = node
        
    def pop(self):
        if self.c[-1] == self.min_elem:
            self.min_elem = self.sec_min_elem
        self.c.pop()
        
    def top(self):
        return self.c[-1]
        
    def min(self):
        return self.min_elem
        
