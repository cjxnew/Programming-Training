// 把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

#include<vector>
#include<set>
#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;

// 方法1：我的方法。可以算，但是复杂度太高，当输入index很大时计算起来会很慢，通过不了牛客的全部用例。
// 因为丑数是由2、3、5的组合乘积得到的，所以我建立一个set，初始set里只有2、3、5三个数
// 然后2、3、5互相相乘，可以得到其他的丑数，每得到一个乘积就把其放到set里，因为set是
// 元素唯一且自动升序排列的容器，所以我只需要往里加，而不需要考虑排序、重复元素的问题
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if(index > 0){
			set<int> uglys;
			uglys.insert(2);
			uglys.insert(3);
			uglys.insert(5);
			while(uglys.size() < index*2){
				fullMultiple(uglys);
			}
			uglys.insert(1);
			int count = 1;
			set<int>::iterator iter = uglys.begin();
			while(count != index)
			{
				++count;
				++iter;
			}
			return *iter;
		}else{
			return 0;
		}
    }

	// 对set中的每个数，都和其他数（也包括和自己）相乘一次，乘积放到set中去
	void fullMultiple(set<int>& u){
		vector<int> tmp(u.begin(), u.end());
		for(int i = 0; i < tmp.size(); ++i){
			for(int j = 0; j < tmp.size(); ++j){
				u.insert(tmp[i]*tmp[j]);
			}
		}
	}
};

// 方法2，也是我的方法，根据分解质因数的思想，找出每个丑数
// 这个方法也能算，但时间复杂度还是达不到要求，通过不了牛客的全部用例（n=1500时）
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if(index <= 0){return 0;}
		vector<int> uglys;
		uglys.push_back(1);
		// 从2开始，依次判断整数是否是丑数
		int n = 2;
		while(uglys.size() < index){
			if(isUgly(n)){
				uglys.push_back(n);
			}
			++n;
		}
		return uglys.back();
	}

	// 使用短除法分解质因数
	bool isUgly(int n){
		while(n > 1){
			for(int i = 2; i <= n; ++i){
				if(n % i == 0){
					n /= i;
					// 判断分解出来的质因数是否属于2、3、5中的一个
					if(i != 2 && i != 3 && i != 5){
						return false;
					}
					break;
				}
			}
		}
		return true;
	}
};

// 方法3，网友最佳答案，是我的方法1的思路的超级精简版
// 首先从丑数的定义我们知道，一个丑数的因子只有2,3,5，那么丑数p = 2^x * 3^y * 5^z，换句话说一个丑数
// 一定由另一个丑数乘以2或者乘以3或者乘以5得到，那么我们从1开始乘以2,3,5，就得到2,3,5三个丑数，在从
// 这三个丑数出发乘以2,3,5就得到4，6,10,6，9,15,10,15,25九个丑数，我们发现这种方法会得到重复的丑数，
// 而且我们题目要求第N个丑数，这样的方法得到的丑数也是无序的。那么我们可以维护三个队列：
// （1）丑数数组： 1
// 乘以2的队列：2
// 乘以3的队列：3
// 乘以5的队列：5
// 选择三个队列头最小的数2加入丑数数组，同时将该最小的数乘以2,3,5放入三个队列；
// （2）丑数数组：1,2
// 乘以2的队列：4
// 乘以3的队列：3，6
// 乘以5的队列：5，10
// 选择三个队列头最小的数3加入丑数数组，同时将该最小的数乘以2,3,5放入三个队列；
// （3）丑数数组：1,2,3
// 乘以2的队列：4,6
// 乘以3的队列：6,9
// 乘以5的队列：5,10,15
// 选择三个队列头里最小的数4加入丑数数组，同时将该最小的数乘以2,3,5放入三个队列......
// 实现思路：
// 我们没有必要维护三个队列，只需要记录三个指针显示到达哪一步

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        // 0-6的丑数分别为0-6
        if(index < 7) return index;
        //p2，p3，p5分别为三个队列的指针，newNum为从队列头选出来的最小数
        int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
        vector<int> arr;
        arr.push_back(newNum);
        while(arr.size() < index) {
            //选出三个队列头最小的数
            newNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
            //这三个if有可能进入一个或者多个，进入多个是三个队列头最小的数有多个的情况
            if(arr[p2] * 2 == newNum) p2++;
            if(arr[p3] * 3 == newNum) p3++;
            if(arr[p5] * 5 == newNum) p5++;
            arr.push_back(newNum);
        }
        return newNum;
    }
};

