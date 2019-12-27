'''
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
'''

# 奇技淫巧
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        try :
            p = float(s)
            return True
        except:
            return False
            
# 正则表达式
import re
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        return re.match(r"^[\+\-]?[0-9]*(\.[0-9]*)?([eE][\+\-]?[0-9]+)?$",s)
        
        
