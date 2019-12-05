# 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符, 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

'''
// 利用hash的思想，用每个字母的ASCII码作来作为数组的index。
// 首先用一个58长度的数组来存储每个字母出现的次数，为什么是58呢，是由于A-Z对应的ASCII码为65-90，a-z对应的ASCII码值为97-122
// 数组长度应为(122-65=57)+1。每个字母的index=int(word)-65，比如'g'=103-65=38，而数组中具体记录的内容是该字母出现的次数，
// 最终遍历一遍字符串，找出第一个数组内容为1的字母就可以了，时间复杂度为O(n)
'''

# 注意在python中，字符转ASCII码使用函数ord()，ASCII码转字符使用函数chr()
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        wordHash = [0]*58
        for word in s:
            asc = ord(word)
            wordHash[asc-65] += 1
        for i in range(len(s)):
            asc = ord(s[i])
            if wordHash[asc-65] == 1:
                return i
        return -1
