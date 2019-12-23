// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
// 数值为0或者字符串不是一个合法的数值则返回0
// 输入描述: 输入一个字符串,包括数字字母符号,可以为空
// 输出描述: 如果是合法的数值表达则返回该数字，否则返回0

#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

// 方法1：我的傻子方法，事实证明我这个实现非常冗余，精简版见方法2.
class Solution {
public:
    long long StrToInt(string str) {
               if(str.size() == 0){return NULL;}
               char hand = 'N';
               int start_pos = 0;
               if(str[0] == '+' || str[0] == '-'){
                       hand = str[0];
                       start_pos = 1;
               }
               // 保存数字序列的数组
               vector<int> num_vec;
               // 创建一个字符和数字的对应字典
               map<char, int> num_map;
               num_map['0'] = 0;
               num_map['1'] = 1;
               num_map['2'] = 2;
               num_map['3'] = 3;
               num_map['4'] = 4;
               num_map['5'] = 5;
               num_map['6'] = 6;
               num_map['7'] = 7;
               num_map['8'] = 8;
               num_map['9'] = 9;
               // 遍历输入字符串str，若便利到的字符是数字，则将对应数字放到数组中，否则是不合法字符串，返回0
               for(int i = start_pos; i < str.size(); ++i){
                       if(num_map.find(str[i]) != num_map.end()){
                               num_vec.push_back(num_map[str[i]]);
                       }else{
                               return 0;
                       }
               }
               // 逆序数字数组，将其转换为数字
               long long ans = 0;
               int base = 1;
               for(auto iter = num_vec.rbegin(); iter != num_vec.rend(); ++iter){
                       ans += (*iter) * base;
                       base *= 10;
               }
               ans = (hand == '-') ? -ans : ans;
               if(-2147483648 > ans || ans > 2147483647){return 0;}
               return ans;
    }
};

// 方法2：思路和我的方法1是一样的，但是实现非常精简。
// 不需要像我一样建一个字典，而是用'0' <= str[i] && str[i] <= '9'就搞定了！
// 即字符之间是可以比较大小的！比较的依据是ASCII码。但是字符不会直接==ASCII码值。
// res = (res << 1) + (res << 3) + (str[i] & 0xf) 即等于 res = res * 10 + str[i] - '0'
// 左移是乘以2的次方。(res << 1) + (res << 3) = res * 2 + res * 8 = res * 10 。 
// 字符'0'到'9'的ascii值的低4个二进制位刚好就是0到9所以str[i]&0xf等于str[i]-'0'。 位运算会比乘法运算效率高那么一点点点点...
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), s = 1; // s代表数字的符号是正还是负
        long long res = 0;
        if(!n) return 0;
        if(str[0] == '-') s = -1;
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){ // 当字符串有符号位，则从第二个字符开始遍历
            if(!('0' <= str[i] && str[i] <= '9')) return 0; 
            res = (res << 1) + (res << 3) + (str[i] & 0xf);
        } 
        return res * s;
    }
};

