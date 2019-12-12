// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;


// 方法1：我的方法。
// （1）建立一个字典容器，我用的是unordered_map，用于保存输入数组中每个元素出现的次数
// （2）遍历原数组一遍，将每个元素的出现次数记录在字典中
// （3）遍历字典，找到出现次数为1的值，将输入的两个指针指向它们
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) {
		if(data.size() < 2){return;}
		unordered_map<int, int> numHash;
		int isFind1 = 0;
		for(int i = 0; i < data.size(); ++i){
			if(numHash.find(data[i]) == numHash.end()){
				numHash[data[i]] = 1;
			}else{
				numHash[data[i]] += 1;
			}
		}
		// 找到字典里出现次数为1的数字，并在输入数组data找到，令指针指向它们
		for(auto iter = numHash.begin(); iter != numHash.end(); ++iter){
			if(iter->second == 1){
				if(isFind1 == 0){
					*num1 = iter->first; // 注意！更改指针所指对象的值，这样来写！
					isFind1 = 1;
				}else{
					*num2 = iter->first;
				}
			}
		}
    }
};

// 方法2：网上的大部分解法，很难理解啊，大神装逼必备答案。
// 首先：位运算中异或的性质：两个相同数字异或=0，一个数和0异或还是它本身。
// 当只有一个数出现一次时，我们把数组中所有的数，依次异或运算，最后剩下的
// 就是落单的数，因为成对儿出现的都抵消了。
// 依照这个思路，我们来看两个数（我们假设是AB）出现一次的数组。我们首先还
// 是先异或，剩下的数字肯定是A、B异或的结果，这个结果的二进制中的1，表现的
// 是A和B的不同的位。我们就取第一个1所在的位数，假设是第3位，接着把原数组
// 分成两组，分组标准是第3位是否为1。如此，相同的数肯定在一个组，因为相同
// 数字所有位都相同，而不同的数，肯定不在一组。然后把这两个组按照最开始的
// 思路，依次异或，剩余的两个结果就是这两个只出现一次的数字。

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
         
        int len=data.size();
        if(len<=2) return;
         
        int one=0;
        for(int i=0;i<len;i++)
        {
            one=one^data[i];
        }
         
        int pos=0;
        int flag=1;
        while(flag)
        {
            if(one&flag)
                break;
            flag=flag<<1;
            pos++;
        }
         
        for(int i=0;i<len;i++)
        {
            if((data[i]&flag)) *num1=*num1^data[i];
            else *num2=*num2^data[i];
        }
    }
     
};

