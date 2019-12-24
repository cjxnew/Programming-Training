// 给定一个数组A[0,1,...,n-1], 请构建一个数组B[0,1,...,n-1], 
// 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

#include<vector>
#include<iostream>
using namespace std;

// 方法1：我的傻瓜方法。直接按题意来累乘，算法复杂度O(n^2)
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B(A.size());
		if(A.size() < 2){return B;}
		for(int i = 0; i < A.size(); ++i){
			int ans = 1;
			for(int j = 0; j < A.size(); ++j){
				if(j == i){continue;}
				ans *= A[j];
			}
			B[i] = ans;
		}
		return B;
	}
};

// 方法2：用两个for循环分别计算a0 * a1 * ... * ai-1和ai+1 * ai+2 * ... * an-1
/*<分析>：
解释下代码，设有数组大小为5。
对于第一个for循环
第一步：b[0] = 1;
第二步：b[1] = b[0] * a[0] = a[0]
第三步：b[2] = b[1] * a[1] = a[0] * a[1];
第四步：b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
第五步：b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
然后对于第二个for循环
第一步
temp *= a[4] = a[4]; 
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
第二步
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
第三步
temp *= a[2] = a[4] * a[3] * a[2]; 
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
第四步
temp *= a[1] = a[4] * a[3] * a[2] * a[1]; 
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
由此可以看出从b[4]到b[0]均已经得到正确计算。*/
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B(A.size());
		if(A.size() == 0){
			return B;
		}
		// 计算a0 * a1 * ... * ai-1
		B[0] = 1;
		for(int i = 1; i < A.size(); ++i){
			B[i] = B[i-1] * A[i-1];;
		}
		// 计算ai+1 * ai+2 * ... * an-1
		int tmp = 1;
		for(int i = A.size()-2; i >= 0; --i){
			tmp *= A[i+1];
            B[i] *= tmp;
		}
		return B;
	}
};

