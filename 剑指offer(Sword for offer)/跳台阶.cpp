// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

// 这其实就是一个斐波那契数列问题:
// n=1，有1种跳法：1
// n=2，有2种跳法：11、2
// n=3，有3种跳法：111、12、21
// n=4，有5种跳法：1111、112、121、211、22
// n=5，有8种跳法：11111、1112、1121、1211、122、2111、221、212
// ......

class Solution {
public:
    int jumpFloor(int number) {
        if(number < 4){
            return number;
        }
        int a = 2, b = 3, result = 0;
        for(int i = 4; i <= number; ++i){
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }

};
