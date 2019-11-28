// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入描述: 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

// 方法1：我的方法。这种全排序问题，属于回溯法，以下代码为固定的解法，需要背
class Solution {
public:
	// 主调函数，调用了递归函数fun
    vector<string> Permutation(string str) {
		// 用于保存所有排序字符串的数组
		vector<string> all_str;
		// 记得加上判空语句
		if(str.size() == 0){return all_str;}
		// 调用fun函数
		fun(str, 0, all_str);
		// 排序成字典序
		sort(all_str.begin(), all_str.end());
		return all_str;
    }

	// fun函数用于递归，其格式是固定的形式，需要背
	void fun(string str, int begin, vector<string>& all_str){
		// 当begin指向str最后一个元素时
		if(begin == str.size()){
			// 由于本题可能出现重复元素，所以会生成相同的序列，这里加上判断，对重复的序列不添加到字符串数组里
			if(find(all_str.begin(), all_str.end(), str) == all_str.end()){
				all_str.push_back(str);
			}
		}
		// 当begin指向的不是最后一个元素时
		else{
			// begin指向的是固定元素。将begin及其往后的元素依次与固定元素交换，递归
			for(int i = begin; i < str.size(); ++i){
				swap(str[i], str[begin]);
				fun(str, begin+1, all_str); // 固定元素往后推移
				swap(str[i], str[begin]);
			}
		}
	}
};

// 方法2：调用C++的next_permutation函数（在algorithm库里）
// 使用do-while+next_permutation的结构。
// 注意next_permutation有两个输入，分别是对象的起始迭代器和结束迭代器；如果对象是数组结构，则输入为next_permutation(a,a+n)的形式

class Solution {
public:
    vector<string> Permutation(string str) {
		vector<string> all_str;
		if(str.size() == 0){return all_str;}
		do{
			all_str.push_back(str);
		}while(next_permutation(str.begin(), str.end()));
		return all_str;
    }
};

