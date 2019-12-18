// LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
// 他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
// “红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以
// 看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),
// “So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何，
// 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


// 方法1：我的方法。
// 已知0能代替任何数，对于除去0之外无重复元素的序列：
// （1）找出输入序列中除去零元素外的最小值min、以及最大值max
// （2）则若输入序列能排成连续序列，则排成的必然是从min到max的这个长为max-min+1的理想序列
// （3）输入序列相对于理想序列的缺少值，必须由0来填补。则输入序列能排成连续序列必须满足的条件是(0的个数)>=(max-min+1)-(非0元素的个数)
// 对于除去0之外有重复元素的序列，返回false
class Solution {
public:
    bool IsContinuous(vector<int> numbers){
		if(numbers.size() == 0){return false;}
		unordered_set<int> figureOverlap(numbers.begin(), numbers.end()); // 用一个集合来统计numbers里的中的重复元素个数
		int overlapNum = numbers.size() - figureOverlap.size(); // 去重之后元素数量的差值
        int maxValue, minValue, zeroCount = 0, noZeroCount = 0;
		int i = 0;
		while(numbers[i] == 0) ++i; // 序列中第一个非零元素
		maxValue = minValue = numbers[i];
		for(auto e : numbers){ // 遍历一遍序列
			if(e == 0){++zeroCount;}
			if(e != 0){
				++noZeroCount;
				if(e < minValue){minValue = e;}
				else if(e > maxValue){maxValue = e;}
			}
		}
		// 当序列中出现重复元素时，只允许重复出现的元素是0
		if(overlapNum > 0){
			if(overlapNum != zeroCount - 1){return false;}
		}
		// 当(0的个数)>=(max-min+1)-(非0元素的个数)时，返回true
		return (zeroCount >= (maxValue - minValue + 1) - noZeroCount);
    }
};
