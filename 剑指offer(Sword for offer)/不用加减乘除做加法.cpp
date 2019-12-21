// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

#include<iostream>
using namespace std;


// 方法1：我的方法。利用递归和++符号。
// （1）当num2 == 1时，num1 + num2就等于++num1
// （2）当num2 != 1时，num1 + num2等于++(num1 + (num2-1))
// 但是这个方法没有通过牛客测试，因为内存超限。递归太耗内存了吗。
class Solution {
public:
    int Add(int num1, int num2){
		if(num2 == 1){return ++num1;}
		int ans = Add(num1, --num2); // 这两句可以合为一句：
		return ++ans; // return 1+Add(num1, --num2);
    }
};

// 方法2：我的方法。利用num1和num2依次递减递增。
class Solution {
public:
    int Add(int num1, int num2){
		if(num2 == 0){return num1;}
		else if(num2 > 0){// 当num2为正整数，让num2递减，num1递增
			while(num2--){
				++num1;
			}
		}else{// 当num2为负整数，让num2递增，num1递减
			while(num2++){
				--num1;
			}
		}
		return num1;//返回num1
    }
};

// 方法3：网友的厉害解法，利用位运算。
/*
1.首先看十进制是如何做的： 5+7=12，三步走
（1）第一步：相加各位的值，不算进位，得到2。
（2）第二步：计算进位值，得到10. 如果这一步的进位值为0，那么第一步得到的值就是最终结果。
（3）第三步：重复上述两步，只是相加的值变成上述两步的得到的结果2和10，得到12。
2.同样我们可以用三步走的方式计算二进制值相加： 5-101，7-111 
（1）第一步：相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111。
（2）第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。
（3）第三步重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1。
 继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果 */
class Solution {
public:
    int Add(int num1, int num2){ 
		return num2 ? Add(num1^num2, (num1&num2)<<1) : num1;
    }
};

int main(){
	Solution s;
	cout << s.Add(6,-2) << endl;
}
