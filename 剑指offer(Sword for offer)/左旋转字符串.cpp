// 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
// 就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请
// 你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要
// 求输出循环左移3位后的结果，即“XYZdefabc”。

#include<string>
using namespace std;


// 方法1：我的方法，可以说很简单很基础了，就是string类的使用
// 左移一次，即把字符串str的首元素取出，放到最后一个位置上去
// 用string::erase函数和string::insert函数即可完成
class Solution {
public:
    string LeftRotateString(string str, int n) {
		string s = str;
		if(str.size() < 2){return s;}
		while(n-- > 0){
			char tmp = s[0];
			s.erase(s.begin());
			s.insert(s.end(), tmp);
		}
		return s;
    }
};

// 方法2：两次翻转字符串
// 如字符串str：abcXYZdef，长度n=9，左移3次得到XYZdefabc
// （1）翻转str得到：fedZYXcba
// （2）翻转str至str+(9-3)得到：XYZdefcba
// （3）翻转str+(9-3)至str.end()得到：XYZdefabc
class Solution {
public:
    string LeftRotateString(string str, int n) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
};

// 方法3：更简单的解法。
// 即左移n次后，s = s[n:] + s[:n]
class Solution {
public:
    string LeftRotateString(string str, int n) {
        string s = str;
		if(str.size() < 2){return s;}
		string s1(s.begin(), s.begin() + n);
		string s2(s.begin() + n, s.end());
		return s2 + s1;
    }
};

