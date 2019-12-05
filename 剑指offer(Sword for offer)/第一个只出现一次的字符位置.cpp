// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
// 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

#include<iostream>
using namespace std;

// 方法1：我的方法。
// 这题较简单，我一次过。
// （1）从头至尾遍历整个字符串，遍历到位置i的字符串时，从i+1的位置一直到字符串尾寻找和str[i]相等的字符
// （2）若找到了，则说明str[i]不止出现一次，为了避免在之后重复比较、产生误判，把和str[i]相等的字符变为'1'作为标记，之后遇到'1'字符直接跳过
// （3）当找到一个只存在一次的字符，返回。当遍历完整个字符串，没找到这样的字符，返回-1.
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
		if(str.size() == 0){return -1;}
		// 遍历字符串
		for(int i = 0; i < str.size(); ++i){
			// 当发现已标记字符，直接跳过
			if(str[i] == '1'){continue;}
			// 对遍历到的每个字符，往后找有没有与之相同的字符
			int isFind = 0;
			for(int j = i+1; j < str.size(); ++j){
				if(str[j] == str[i]){
					// 发现相同的字符，则打上标记
					str[j] = '1';
					isFind = 1;
				}
			}
			// 没发现相同的字符，则返回该位置
			if(isFind == 0){return i;}
		}
		return -1;
    }
};

// 方法2：网友的巧用hash表的方法，时间复杂度只有O(n)，比我的好
// 利用hash的思想，用每个字母的ASCII码作来作为数组的index。
// 首先用一个58长度的数组来存储每个字母出现的次数，为什么是58呢，是由于A-Z对应的ASCII码为65-90，a-z对应的ASCII码值为97-122
// 数组长度应为(122-65=57)+1。每个字母的index=int(word)-65，比如'g'=103-65=38，而数组中具体记录的内容是该字母出现的次数，
// 最终遍历一遍字符串，找出第一个数组内容为1的字母就可以了，时间复杂度为O(n)
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
		if(str.size() == 0){return -1;}
		int wordHash[58] = {0};
		for(int i = 0; i < str.size(); ++i){
			char tmp = str[i];
			++wordHash[tmp-65];
		}
		for(int i = 0; i < str.size(); ++i){
			char tmp = str[i];
			if(wordHash[tmp-65] == 1){
				return i;
			}
		}
		return -1;
    }
};

