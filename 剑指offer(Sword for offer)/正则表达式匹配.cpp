// 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
// 而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有
// 字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 方法1：我的方法。没通过。。。。
// 利用一个队列，把模式字符串放进去，然后出队依次与目标字符串比较
// 令模式字符串中*前面的字符叫做复写字符，而.叫做替代字符
class Solution {
public:
    bool match(char* str, char* pattern){
		// （1）初始判断
		int str_len = strlen(str);
		int pat_len = strlen(pattern); // 注意计算字符数组的长度，用strlen！ 而不能用sizeof(str)/sizeof(char)！！！判断字符数组是否相等，用strcmp！ 相等的话函数返回0！而不能用 == ！
		if(str_len == 0 || str_len == 1){
			if(str_len == 0 && pat_len == 0){return true;}
			else if(pat_len == 2 && pattern[1] == '*'){return true;}
			else{return false;}
		}
		if(str_len != 0 && pat_len == 0){return false;}
        // （2）模式字符串入队
		// 在队列中，我们用*元素标记接下来的front元素是一个复写字符。所以第一步先将pattern字符中的*和*之前的字符换位置
		queue<char> pat_queue;
		for(int i = 0; i < pat_len; ++i){
			if(pattern[i] == '*'){
				char tmp = pattern[i];
				pattern[i] = pattern[i-1];
				pattern[i-1] = tmp;
			}
		}
		// 元素依次进队
		for(int i = 0; i < pat_len; ++i){
			pat_queue.push(pattern[i]);
		}
		// （3）依次出队与目标字符串比较
		int i = 0;
		while(i != str_len){
			if(pat_queue.empty()){return false;}
			char cmp = pat_queue.front();
			pat_queue.pop();
			if(cmp == '*'){ // 当队首元素为*，则下一个队首元素是复写字符
				cmp = pat_queue.front();
				pat_queue.pop();
				if(str[i] == cmp){
					while(str[i] == cmp){++i;};
				}
			}else if(cmp == '.'){ // 当队首元素为.，则i直接+1
				++i;
			}else{ // 否则，比较队首元素和str[i]，若不相等则返回false
				if(str[i] != cmp){return false;}
				++i;
			}
		}
		if(!pat_queue.empty()){return false;} // 若遍历完str，队列不为空，返回false
		return true;
    }
};

// 方法2：这题用递归来做。
/*
    解这题需要把题意仔细研究清楚，反正我试了好多次才明白的。
    首先，考虑特殊情况：
         1>两个字符串都为空，返回true
         2>当第一个字符串不空，而第二个字符串空了，返回false（因为这样，就无法
            匹配成功了,而如果第一个字符串空了，第二个字符串非空，还是可能匹配成
            功的，比如第二个字符串是“a*a*a*a*”,由于‘*’之前的元素可以出现0次，
            所以有可能匹配成功）
    之后就开始匹配第一个字符，这里有两种可能：匹配成功或匹配失败。但考虑到pattern
    下一个字符可能是‘*’， 这里我们分两种情况讨论：pattern下一个字符为‘*’或
    不为‘*’：
          1>pattern下一个字符不为‘*’：这种情况比较简单，直接匹配当前字符。如果
            匹配成功，继续匹配下一个；如果匹配失败，直接返回false。注意这里的
            “匹配成功”，除了两个字符相同的情况外，还有一种情况，就是pattern的
            当前字符为‘.’,同时str的当前字符不为‘\0’。
          2>pattern下一个字符为‘*’时，稍微复杂一些，因为‘*’可以代表0个或多个。
            这里把这些情况都考虑到：
               a>当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，
                跳过这个‘*’符号；
               b>当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符
                不变。（这里匹配1个或多个可以看成一种情况，因为：当匹配一个时，
                由于str移到了下一个字符，而pattern字符不变，就回到了上边的情况a；
                当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配）
    之后再写代码就很简单了。
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        //if the next character in pattern is not '*'
        if (*(pattern+1) != '*')
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str+1, pattern+1);
            else
                return false;
        }
        //if the next character is '*'
        else
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern+2) || match(str+1, pattern);
            else
                return match(str, pattern+2);
        }
    }
};

// 方法3：和方法2差不多，但是解释地更好，代码也更好理解。
/*
要分为几种情况：（状态机）
（1）当第二个字符不为‘*’时：匹配就是将字符串和模式的指针都下移一个，不匹配就直接返回false
（2）当第二个字符为'*'时：
        匹配：
                a.字符串下移一个，模式不动
                b.字符串下移一个，模式下移两个
                c.字符串不动，模式下移两个
        不匹配：字符串下移不动，模式下移两个
搞清楚这几种状态后，用递归实现即可：
*/
class Solution {
public:
    bool match(char* str, char* pattern){
        if(str[0] == '\0' && pattern[0] == '\0' )
            return true;
        else if(str[0] != '\0' && pattern[0] == '\0')
            return false;
        if(pattern[1] != '*'){
            if(str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0'))
                return match(str+1, pattern+1); // 把str、pattern首元素的下一个位置作为输入，递归
            else
                return false;
        }
        else{
            if(str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0'))
                return match(str, pattern+2) || match(str+1, pattern) || match(str+1, pattern+2);
            else
                return match(str, pattern+2);
        }
    }
};

