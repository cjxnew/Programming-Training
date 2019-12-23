// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
// 但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个
// 重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false

#include<iostream>
#include<unordered_map>
using namespace std;

// 方法1：我的方法。
// 利用字典保存数组中每个数字出现的次数
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
		if(length < 2){return false;}
		unordered_map<int, int> num_map; // 字典
		// 将数组中出现的数字作为键值放到字典里
		for(int i = 0; i < length; ++i){
			if(numbers[i] < 0 || numbers[i] >= length){return false;}
			num_map[numbers[i]] += 1;
		}
		// 找到数组中第一个重复出现的数字
		for(int i = 0; i < length; ++i){
			if(num_map[numbers[i]] > 1){
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
    }
};

// 方法2：网友的极简实现，空间O(1)，时间O(n)
// 不需要额外的数组或者hash table来保存，题目里写了数组里数字的范围保证在0 ~ n-1 之间，
// 所以可以利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，之后
// 再遇到相同的数时，会发现对应位上的数已经大于等于n了，那么直接返回这个数即可。
bool duplicate(int numbers[], int length, int* duplication) {
    for(int i=0;i!=length;++i){
        int index=numbers[i]%length;
        if(numbers[index]>=length){
            *duplication=index;
            return 1;
        }              
        numbers[index]+=length;  
    }
    return 0;
}
