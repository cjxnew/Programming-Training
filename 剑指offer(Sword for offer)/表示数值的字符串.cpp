// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

#include<iostream>
#include<string>
using namespace std;


// 方法1：我的方法。分几种情况来讨论。
// （1）判断字符串是不是合格的小数（带小数点的数）
// （2）判断字符串是不是合格的整数（前缀有0或1个正负号）
// （3）判断字符串是不是合格的科学计数法（带e或E的数，e前面必须是合格的整数或小数，e后面必须是整数）
class Solution {
public:
    bool isNumeric(char* s){
        int size = strlen(s);
		if(size == 0){return false;}
		int e_pos = 0, e_num = 0;
		for(int i = 0; i < size; ++i){ // 找到e或E出现的次数和位置
			if(s[i] == 'e' || s[i] == 'E'){
				++e_num;
				if(e_num > 1){return false;}
				e_pos = i;
			}
		}
		// 若不是科学计数法数字（不带e和E）
		if(e_num == 0){
			return isXiaoshu(s) || isZhengshu(s);
		}else{ // 若是科学计数法数字，把该数字以E位置划分为前后两部分，前部分必须是小数，后部分必须是整数
			string pre_part = string(s).substr(0, e_pos);
			cout << pre_part << endl;
			cout << s+e_pos+1 << endl;
			return isXiaoshu((char*)pre_part.c_str()) && isZhengshu(s+e_pos+1);
		}
    }

	// 判断数字是否是合格的小数（包括整数）
	bool isXiaoshu(char* s){
		int size = strlen(s); // 字符串长度
		if(size == 0){return false;}
		int pre_num = 0; // 前缀正负号个数
		while(s[pre_num] == '+' || s[pre_num] == '-'){++pre_num;}
		if(pre_num > 1){return false;}
		char *numeric = s + pre_num; // 除去符号位的数值部分
		if(strlen(numeric) == 0 || numeric[0] == '0'){return false;} // 数字开头不能为0
		int dot_num = 0;
		for(int i = 0; i < size-pre_num; ++i){ // 判断小数点个数是否合法、字符是不是数字
			if(numeric[i] == '.'){
				++dot_num;
				if(i == size-pre_num-1){return false;} // 小数点后必须有数字
				if(dot_num > 1){return false;} // 小数点个数不能超过1
			}else if(numeric[i] < '0' || numeric[i] > '9'){
				return false;
			}
		}
		return true;
	}

	// 判断数字是否是合格的整数
	bool isZhengshu(char* s){
		int size = strlen(s); // 字符串长度
		if(size == 0){return false;}
		int pre_num = 0; // 前缀正负号个数
		while(s[pre_num] == '+' || s[pre_num] == '-'){++pre_num;}
		if(pre_num > 1){return false;}
		char *numeric = s + pre_num; // 除去符号位的数值部分
		if(strlen(numeric) == 0 || numeric[0] == '0'){return false;} // 数字开头不能为0
		for(int i = 0; i < size-pre_num; ++i){ // 判断字符是不是数字
			if(numeric[i] < '0' || numeric[i] > '9'){
				return false;
			}
		}
		return true;
	}
};


// 方法2：网友的思路，比我的精简一些
class Solution {
public:
    bool isNumeric(char* str) {
        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'e' || str[i] == 'E') {
                if (i == strlen(str)-1) return false; // e后面一定要接数字
                if (hasE) return false;  // 不能同时存在两个e
                hasE = true;
            } else if (str[i] == '+' || str[i] == '-') {
                // 第二次出现+-符号，则必须紧接在e之后
                if (sign && str[i-1] != 'e' && str[i-1] != 'E') return false;
                // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
                if (!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
                sign = true;
            } else if (str[i] == '.') {
              // e后面不能接小数点，小数点不能出现两次
                if (hasE || decimal) return false;
                decimal = true;
            } else if (str[i] < '0' || str[i] > '9') // 不合法字符
                return false;
        }
        return true;
    }
};

