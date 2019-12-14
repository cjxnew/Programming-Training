// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 方法1：我的方法。
// 既然是有序的数组，则用折半查找的思路来做。
// （1）从左到右遍历输入数组array
// （2）对遍历到的当前数字base，令goal=sum-base
// （3）在数组array中，用折半查找的方法，找base的右边那些元素中是否存在goal
// （4）若有，则加入到一个数组ans中。
// （5）最后定义一个compare规则，对ans数组中的数字对进行排序（乘积小的放前面），返回ans[0]
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if(array.size() < 2){
			vector<int> empty;
			return empty;
		}
        vector<vector<int> > ans;
		// 对array中的每一个数字base，都对array中位于base右边的元素进行折半查找，寻找是否存在sum-base这个数
		for(int i = 0; i < array.size()-1; ++i){
			int base = array[i];
			int goal = sum - base;
			bool isFind = false;
			// 对base元素右边剩下元素中进行折半查找，寻找goal
			int low = i + 1, high = array.size()-1, mid;
			while(low <= high){
				mid = (low + high) / 2;
				if(array[mid] == goal){isFind = true;break;}
				else if(array[mid] < goal){
					low = mid + 1;
				}else{
					high = mid - 1;
				}
			}
			// 若goal存在于数组中，则保存到ans数组
			if(isFind == true){
				vector<int> a_ans;
				a_ans.push_back(base);
				a_ans.push_back(goal);
				ans.push_back(a_ans);
			}
		}
		// 找到ans数组中乘积最小的那一对数字
		if(ans.size() == 0){
			vector<int> final_ans;
			return final_ans;
		}else{
			sort(ans.begin(), ans.end(), compare);
			return ans[0];
		}
    }

	//static bool compare(const vector<int>& a, const vector<int>& b)
	static bool compare(vector<int> a, vector<int> b){
		return a[0] * a[1] < b[0] * b[1];
	}
};

// 方法2：用双指针方法解决，比我的方法时间复杂度低，也不需要排序。
// 因为数列满足递增，设两个头尾两个指针i和j，
// 若ai + aj == sum，就是答案（相差越远乘积越小）
// 若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
// 若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
// 时间复杂度O(n)
typedef vector<int> vi;
class Solution {
public:
    vi FindNumbersWithSum(const vi& a,int sum) {
        vi res;
        int n = a.size();
        int i = 0, j = n - 1;
        while(i < j){
            if(a[i] + a[j] == sum){
                res.push_back(a[i]);
                res.push_back(a[j]);
                break;
            }
            while(i < j && a[i] + a[j] > sum) --j;
            while(i < j && a[i] + a[j] < sum) ++i;
        }
        return res;
    }
};

