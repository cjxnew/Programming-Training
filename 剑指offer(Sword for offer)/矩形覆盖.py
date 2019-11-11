# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        f1 = 1
        f2 = 2
        if number == 0:
            return 0
        elif number == 1:
            return f1
        elif number == 2:
            return f2
        else:
            for i in xrange(2, number):
                f3 = f1 + f2
                f1 = f2
                f2 = f3
            return f3
