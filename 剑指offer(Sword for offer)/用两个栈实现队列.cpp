// 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

// 思路：push操作：栈1专门用来接收push进来的元素。
//       pop操作：当栈2为空，将栈1的元素都push到栈2中，再从栈2里pop出去；当栈2不为空，直接从栈2pop出去。
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if(stack1.empty() && stack2.empty()){return -1;}
		else{
			if(stack2.empty()){
				while(!stack1.empty()){
					int tmp = stack1.top();
					stack1.pop();
					stack2.push(tmp);
				}
				int tmp = stack2.top();
				stack2.pop();
				return tmp;
			}else{
				int tmp = stack2.top();
				stack2.pop();
				return tmp;
			}
		}
	}

	bool empty() {
		if(stack1.empty() && stack2.empty()){return true;}
		else{return false;}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
