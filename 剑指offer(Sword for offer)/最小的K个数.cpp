// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;


// 方法1，使用利用红黑树自动排序的set容器
// 注意set容器不支持[i]索引、且set的迭代器不支持加减法
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        set<int> num_set;
		vector<int> num_vector;
		if(input.size() == 0 || k <= 0 || k > input.size()){return num_vector;}
		// 把所有元素都放到set里
		for(auto i : input){
			num_set.insert(i);
		}
		// 取set的前k个数输出
		int count = 0;
		for(auto i = num_set.begin(); i != num_set.end(); ++i){
			num_vector.push_back(*i);
			++count;
			if(count == k){break;}
		}
		return num_vector;
    }
};


// 方法2，使用sort对数组进行排序，再输出前k个数
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if(input.size() == 0 || k <= 0 || k > input.size()){return ans;}
        sort(input.begin(), input.end());
		ans.assign(input.begin(), input.begin()+k);
		return ans;
    }
};

