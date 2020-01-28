// 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
// 那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取
// 数据流，使用GetMedian()方法获取当前读取数据的中位数。

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

// 方法1：我的方法。一刷12mins，较简单
// 在类里创建一个保存double类型数字的vector数组
// Insert往数组里加数字
// GetMedian则对数组进行排序之后，输出中位数
class Solution {
	vector<double> data;
public:
    void Insert(int num){
		data.push_back(num);
    }

    double GetMedian(){
		sort(data.begin(), data.end());
		if(1 == data.size() % 2){
			return data[data.size()/2];
		}else{
			return (data[data.size()/2] + data[data.size()/2 - 1])/2.0;
		}
    }
};

// 方法2：网友的方法。
// 为了避免每次插入都进行排序带来的开销。建立两个堆：一个大顶堆、一个小顶堆。
// 维持大顶堆的数都小于等于小顶堆的数，且两者的个数相等或差1。则，中位数就是两个堆的堆顶元素的平均数。
class Solution {
    priority_queue<int, vector<int>, less<int> > p;
    priority_queue<int, vector<int>, greater<int> > q;

public:
    void Insert(int num){
        if(p.empty() || num <= p.top()) p.push(num);
        else q.push(num);
        if(p.size() == q.size() + 2) q.push(p.top()), p.pop();
        if(p.size() + 1 == q.size()) p.push(q.top()), q.pop();
    }
    double GetMedian(){ 
      return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};

