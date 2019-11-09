 // 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39

 // 斐波那契数列的定义：指的是这样一个数列：1、1、2、3、5、8、13、21、34、……在数学上，
 // 斐波那契数列以如下被以递推的方法定义：F(1)=1，F(2)=1, F(n)=F(n-1)+F(n-2)（n>=3，n∈N*）


// 方法1：递归。没问题，但是程序运行超时
class Solution {
public:
    int Fibonacci(int n) {
		if(n == 0){return 0;}
		if(n == 1){return 1;}
		return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};

// 方法2：用for循环实现递归
class Solution {
public:
    int Fibonacci(int n) {
		if(n < 2){return n;}
		int a = 0, b = 1, result;
		for(int i = 2; i <= n; ++i){
			result = a + b;
			a = b;
			b = result;
		}
		return result;
    }
};
