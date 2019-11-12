
// 方法1：我的思路。若指数为0返回1，若指数为正整数则循环乘base，若指数为负整数则循环乘1/base。
class Solution {
public:
    double Power(double base, int exponent) {
		if(exponent == 0){return 1.;}
		double b = (exponent > 0)?(base):(1./base);
		double result = b;
		int index = abs(exponent);
		while(index > 1){
			result *= b;
			--index;
		}
		return result;
    }
};

// 方法2：直接调用pow函数，这个不用多说了吧
class Solution {
public:
    double Power(double base, int exponent) {
		return pow(base, exponent);
    }
};
