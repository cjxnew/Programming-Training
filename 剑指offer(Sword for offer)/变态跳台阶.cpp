// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

// 方法1：递归。假设当前位置距离终点还有n步，则开始这次跳台阶之前，有1~n这n种步伐选择。利用这种思想，跳全局第一步可看作是计算jumpFloorII(n)，
// 然后如果第一步跳了1，则第二步相当于是计算jumpFloorII(n-1)。
// 把从1~n这n个位置的jumpFloorII值算出来相加，就等于答案
// 当全局第一步就跳了n步时，相当于求jumpFloorII(0)，于是我令jumpFloorII(0)=jumpFloorII(1)=1

// 一次过！还有谁！纯自己想的！

class Solution {
public:
    int jumpFloorII(int number) {
        if(number < 2){return 1;}
        int count = 0;
        for(int i = 1; i <= n; ++i){
            count += jumpFloorII(number - i);
        }
        return count;
    }
};

// 方法2：大部分人的解法。jumpFloorII(n)=2^(n-1)
// 每个台阶可以看作一块木板，让青蛙跳上去，n个台阶就有n块木板，最后一块木板是青蛙到达的位子， 
// 必须存在，其他 (n-1) 块木板可以任意选择是否存在，则每个木板有存在和不存在两种选择，(n-1) 块木板 就有 [2^(n-1)] 种跳法，可以直接得到结果。
// n=1，有1种跳法：1
// n=2，有2种跳法：11、2
// n=3，有4种跳法：111、12、21、3
// n=4，有8种跳法：1111、112、121、211、22、......
// ......

class Solution {
public:
    int jumpFloorII(int number) {
    if (number==0)
        return 0;
        int total = 1;
        if (number==1)
            return 1;
        for (int i=1; i<number;i++)
            {
            total*=2;
        }
        return total;
             
    }
};
