// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

#include<vector>
#include<iostream>
using namespace std;
// 这题我没做出来，看看别人的做法

// 方法1：利用短路原理，实现递归
// &&就是逻辑与，逻辑与有个短路特点，前面为假，后面不计算。
class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1)); // 当ans=0，递归结束
        return ans;
    }
};

// 方法2：用歪门邪道的方法来实现等差数列求和公式 —— n*(n+1)/2
class Solution {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1]; // 但是，一般的编译器不支持这样用变量给数组初始化
        return sizeof(a)>>1; // 每个bool元素占一个字节，a的字节数等于n*(n+1)。二进制右移一位等价于除以2.
    }
};

// 方法3：高端解法。设置一个辅助类，类里有静态变量N和sum，在辅助类的构造函数中进行sum的累加运算
// 设置一个静态变量N和sum，在构造函数中进行累加运算：
class assist{
public:
    assist() {N++;sum += N;} // 构造函数
    static unsigned int GetSum(){return sum;}
private:
    static int N;
    static int sum;
};
int assist::N = 0;
int assist::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        assist * p = new assist[n]; // 构造一个以辅助类为类型、大小为n的数组，重复调用此构造函数n次来实现n次的累加运算
        delete []p;
        p = nullptr;
        return assist::GetSum();
    }
};

// 方法4：高端解法。使用模板函数进行编程，显式定义输入参数为1的模块
// 我不太理解。。。惭愧
template <int m> inline int SumTo() { return m + SumTo<m-1>(); }  template <> inline int SumTo<1>() { return 1; }


// 方法5：高端解法。使用虚函数
// 我不太理解。。。惭愧
class Base;
Base* Array[2];
class Base{
public:
     virtual int Sum(int n){return 0;}
};
class Derived : public Base{
public:
    virtual int Sum(int n){return Array[!!n]->Sum(n-1) + n;}
};
// 使用虚函数来构造递归，在基类种定义虚函数Sum(n)返回0，通过将指针数组的两个元素分别绑定到基类和派生类，其中基类的Sum()
// 结束递归，!!n来构造true(1) false(0)来对指针数组进行访问
class Solution {
public:
    int Sum_Solution(int n) {
        Base a;
        Derived b;
        Array[0] = &a;
        Array[1] = &b;
        return b.Sum(n);
    }
};
