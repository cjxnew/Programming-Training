// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

// 经我推算，这又是一个斐波那契数列问题
// n=1时，有1种拼法
// n=2时，有2种拼法
// n=3时，有3种拼法
// n=4时，有5种拼法
// n=5时，有8种拼法
// n=6时，有13种拼法
// ......

class Solution {
public:
    int rectCover(int number) {
        if(number < 4){return number;}
        return rectCover(number - 1) + rectCover(number - 2);
    }
};
