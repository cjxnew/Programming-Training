// 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下
// 四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机
// 器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
// 请问该机器人能够达到多少个格子？

// 一刷37mins，未做出来，几乎要做出来了。
// 一刷38mins，做出来了！原来是把题目要求搞错了。题目说大于给定值的位置不能去，我以为是等于给定值的位置不能去。。。
// 我的方法：用回溯法（好像也是DFS的思路），递归求解。
// （1）首先创建一个大小为rows*cols的一维bool数组，来表示二维数组，并初始化为全false
// （2）将bool数组上，满足“机器人不能去”要求的位置都设为true
// （3）利用countCanPos函数进行递归，回溯地寻找所有可以到达的位置：
// --- 1.用i，j表示当前的数组位置，若i，j未越界且bool数组的这个位置不为true，则令计数器count+1；
// --- 2.对当前位置上下左右位置递归求解。
class Solution {
public:
    int movingCount(int threshold, int rows, int cols){
        bool *isBanPos = new bool[rows*cols](); // 加上小括号，进行默认初始化，默认元素全为false
		// 将bool数组上，满足“机器人不能去”要求的位置都设为true
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < cols; ++j){
				if(threshold < addPart(i) + addPart(j)){
					isBanPos[cols*i+j] = true;
				}
			}
		}
		// 设置计数器、机器人起始位置
		int count = 0;
		int i = 0, j = 0;
		countCanPos(isBanPos, rows, cols, i, j, count);
		delete[] isBanPos;
		return count;
    }

	// 计算数位加和的小函数
	int addPart(int num){
		if(num >= 0 && num < 10){return num;}
		int sum = 0;
		while(num > 0){
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}

	// 回溯法递归函数
	void countCanPos(bool* &isBanPos, int rows, int cols, int i, int j, int &count){
		if(i < 0 || i >= rows || j < 0 || j >= cols || isBanPos[cols*i+j] == true){
			return;
		}
		++count;
		isBanPos[cols*i+j] = true;
		countCanPos(isBanPos, rows, cols, i-1, j, count);
		countCanPos(isBanPos, rows, cols, i+1, j, count);
		countCanPos(isBanPos, rows, cols, i, j-1, count);
		countCanPos(isBanPos, rows, cols, i, j+1, count);
	}

};

