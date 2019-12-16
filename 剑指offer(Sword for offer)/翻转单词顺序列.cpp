// 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
// 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
// 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正
// 确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

#include<iostream>
#include<vector>
#include<string>
using namespace std;


// 方法1：我的方法。
// 建立str_tmp用于保存遍历输入字符串的单词，建立str_set保存输入字符串的所有单词
// （1）先遍历输入字符串str，当遇到空格或者遍历到str末尾，则把当前单词放到str_set里
// （2）逆序遍历str_set，将单词拼接到str_tmp里，返回str_tmp
class Solution {
public:
    string ReverseSentence(string str) {
		if(str.size() < 2){return str;}
        vector<string> str_set;
		string str_tmp;
		for(int i = 0; i < str.size(); ++i){
			if(str[i] == ' ' || i == str.size()-1){
				if(i == str.size()-1){str_tmp += str[i];}
				str_set.push_back(str_tmp);
				str_tmp.clear();
				continue;
			}
			str_tmp += str[i];
		}
		for(auto iter = str_set.rbegin(); iter != str_set.rend(); ++iter){
			str_tmp += *iter;
			if(iter != str_set.rend()-1){
				str_tmp += ' ';
			}
		}
		return str_tmp;
    }
};

// 方法2：从前往后一直读取，遇到空格之后就把之前读取到的压到结果的前面并添加上空格。
// 最后当循环结束，如果那个用来读取的字符串不为空，那么就再把它压到结果前，这次就
// 不用再结果的最前面加空格了
class Solution {
public:
    string ReverseSentence(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i){
            if(str[i] == ' ') res = " " + tmp + res, tmp = "";
            else tmp += str[i];
        }
        if(tmp.size()) res = tmp + res;
        return res;
    }
}; 

