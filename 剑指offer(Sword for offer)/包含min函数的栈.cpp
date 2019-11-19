// 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

#include<iostream>
#include<vector>
using namespace std;
#define BIG_NUM 99999

// 我的方法：在push、pop的过程中记录最小元素值，min时直接返回最小元素。我感觉我的方法比方法2好。
class Solution {
public:
	// 构造函数
	Solution():min_elem(BIG_NUM), sec_min_elem(BIG_NUM){};

    void push(int value) {
        c.push_back(value);
		// 在每次push，都判断其是否是最小元素值
		if(value < min_elem){
			sec_min_elem = min_elem;
			min_elem = value;
		}
    }
    void pop() {
		if(c.size() == 0){return;}
		// 如果pop出去的元素是最小元素，则更新新的最小元素值
		if(c.back() == min_elem){
			min_elem = sec_min_elem;
		}
        c.pop_back();
    }
    int top() {
        if(c.size() == 0){return -1;}
		return c.back();
    }
    int min() {
        return min_elem;
    }
private:
	vector<int> c;
	int min_elem; // 保存栈的最小元素值
	int sec_min_elem; // 保存栈的第二小元素值
};

// 方法2：应用一个辅助栈，我们叫它最小元素栈. 每次压栈操作时, 如果压栈元素比当前最小元素更小, 就把这个元素压入最小元素栈, 
// 原本的最小元素就成了次小元素. 同理, 弹栈时, 如果弹出的元素和最小元素栈的栈顶元素相等, 就把最小元素的栈顶弹出.
class Solution {
public:
    void push(int value) {
        s.push(value);
        if(sMin.empty())
            sMin.push(value);
        else if(value <= sMin.top())
            sMin.push(value);
    }
    void pop() {
        if(s.top() == sMin.top())
            sMin.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return sMin.top();
    }
private:
    stack<int> s;
    stack<int> sMin;
};

