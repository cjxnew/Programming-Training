// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
// 但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
// 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

#include<vector>
#include<iostream>
using namespace std;


// 我的土办法，其实速度挺快的。好像也是最多网友用的方法。
// 先写一个统计整数n有几个1的函数countOne，再对1~n这n个整数都调用countOne，统计一共出现的1的次数
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		if(n <= 0){return 0;}
		int count = 0;
		for(int i = 1; i <= n; ++i){
			count += countOne(i);
		}
		return count;
    }

	// 统计一个整数中1的个数
	// 根据十进制数除以10的余数为位数值的规律来写
	int countOne(int n){
		int count = 0;
		while(n != 0){
			if(n % 10 == 1){
				++count;
			}
			n /= 10;
		}
		return count;
	}
};

