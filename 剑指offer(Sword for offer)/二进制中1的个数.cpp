// 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。



// 方法1：我的傻瓜思路。把位运算转化为我们理解的形式。
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int _n = abs(n);
		 int count = 0;
		 vector<int> bin;
		 while(_n){
			 bin.push_back(_n % 2);
			 _n /= 2;
		 }
		 if(n >= 0){// 当n为正数
			 for(int i = 0; i < bin.size(); ++i){
				 if(bin[i] == 1){++count;}
			 }
		 }else{// 当n为负数
			 while(bin.size() < 31){bin.push_back(0);} // 负数表示为32位补码。先将除了符号位(1)外位数值填0，得到原码
			 for(int i = 0; i < bin.size(); ++i){(bin[i]==1)?(bin[i]=0):(bin[i]=1);} // 得到反码
			 // 二进制数加1
			 for(int i = 0; i < bin.size(); ++i){
				 if(bin[i] == 0){
					 bin[i] = 1;
					 break;
				 }else{
					bin[i] = 0;
				 }
			 }// 二进制数加1
			 // 统计1的个数
			 for(int i = 0; i < bin.size(); ++i){
				 if(bin[i] == 1){++count;}
			 }
			 ++count; // 负数加上符号位1
		 }
		 return count;
     }
};

// 方法2：正数负数都通用，这个方法真的很棒！
// 把这个数逐次 右移 然后和1 与,
// 就得到最低位的情况,其他位都为0,
// 如果最低位是0和1与 之后依旧 是0，如果是1，与之后还是1。
// 对于32位的整数 这样移动32次 就记录了这个数二进制中1的个数了
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         for(int i=0;i<32;i++){ // 在这里默认了int是32位（4字节），更一般的写法是sizeof(int)*8
            if(n>>i&1)  // n>>i代表n的二进制表示数向右移i位，&代表位与运算
                count++;
         }
         return count;
     }
};

// 方法3：和方法2不同的是，这里是移动一个游标，来判断n的各个二进制位置是不是1
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         unsigned int flag=1;
         while(flag){
             if (n & flag){
                 count++;
             }
          flag=flag<<1;
         }
         return count;
     }
};
