// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
// 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

#include<vector>
#include<iostream>
#include<stack>
using namespace std;

// 方法1：我的方法。直接遍历两个序列，用一个栈来模拟这个入栈、出栈的过程
// 借用一个辅助的栈，遍历压栈顺序，先讲第一个放入栈中，这里是1，然后判断栈顶元素是不是出栈顺序的第一个元素，
// 这里是4，很显然1≠4，所以我们继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，
// 直到不相等，这样循环等压栈顺序遍历完成，如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
		int popIndex = 0, pushIndex = 0;
		// 遍历入栈序列和出栈序列，依次入栈出栈操作
		while(popIndex < popV.size()){
			// 当入栈序列未遍历完，则入栈
			if(pushIndex < pushV.size()){
				s.push(pushV[pushIndex++]);
			}
			// 若栈顶元素等于当前等待出栈元素，则出栈，注意要用while
			while(!s.empty() && s.top() == popV[popIndex]){ // 注意！当栈为空时使用top()函数会报错！
				s.pop();
				++popIndex;
			}
			// 若入栈元素都入完了，也经过了出栈操作，但是栈不为空，说明出栈不成功，返回false
			if(pushIndex == pushV.size() && !s.empty()){
				return false;
			}
		}
		// 若能成功从while循环里出来，则返回true
		return true;
    }
};

// 方法2：和我的思路完全一样，但是实现比我简洁
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        vector<int> stack;
        for(int i = 0,j = 0 ;i < pushV.size();){
            stack.push_back(pushV[i++]);
            while(j < popV.size() && stack.back() == popV[j]){
                stack.pop_back();
                j++;
            }      
        }
        return stack.empty();
    }
};

