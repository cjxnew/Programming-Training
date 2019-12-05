// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

#include<iostream>
#include<vector>
#include<sstream> // stringstream
#include<algorithm> // max_element 返回指向最大元素的迭代器
using namespace std;


// 方法1：我的方法。
// （1）先使用全排列算法，得到所有可能的数字组合，以vector<vector<int> > allPossibleNumVector的形式保存
// （2）再利用stringstream流，将这些数字组合转化为数字（long类型），保存在vector<long> allPossibleNum
// （3）最后选出vector<long> allPossibleNum中最小的数字，用to_string方法转化为string类型返回
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
		if(numbers.size() == 0){return "";}
        vector<vector<int> > allPossibleNumVector;
		// 得到数字的全排列组成的数组
		fun(numbers, 0, allPossibleNumVector);
		// 将数组转化为拼接成的数字，放到allPossibleNum数组里
		vector<long> allPossibleNum;
		for(auto i : allPossibleNumVector){
			stringstream ss; // 使用stringstream流，方便地拼接数字
			long num;
			for(auto j : i){
				ss << j;
			}
			ss >> num;
			allPossibleNum.push_back(num);
		}
		long ans = *min_element(allPossibleNum.begin(), allPossibleNum.end()); // max_element 返回指向最大元素的迭代器
		return to_string(ans);
    }

	// 得到数字的全排列组成的数组
	// 全排列的固定递归写法
	void fun(vector<int> numbers, int begin, vector<vector<int> >& allPossibleNumVector){
		if(begin == numbers.size()){
			allPossibleNumVector.push_back(numbers);
		}else{
			for(int i = begin; i < numbers.size(); ++i){
				swap(numbers[i], numbers[begin]);
				fun(numbers, begin+1, allPossibleNumVector);
				swap(numbers[i], numbers[begin]);
			}
		}
	}
};

// 方法2：定义一个排序规则，进行排序
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len == 0) return "";
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i < len; i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};
