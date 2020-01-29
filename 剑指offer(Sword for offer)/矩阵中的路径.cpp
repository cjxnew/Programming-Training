// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
// 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，
// 向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入
// 该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
// 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二
// 个格子之后，路径不能再次进入该格子。

// bool hasPath(char* matrix, int rows, int cols, char* str)
// 其中matrix是一个一维字符数组，rows和cols代表假定这个一位数组表示成的二维数组的行和列，str是要查找的路径，也是一个字符数组

// 方法1：网友的解法，使用回溯法的思想，利用递归来求解。
// 分析：回溯算法
//   这是一个可以用回朔法解决的典型题。首先，在矩阵中任选一个格子作为路径的起点。
// 如果路径上的第i个字符不是ch，那么这个格子不可能处在路径上的第i个位置。如果路
// 径上的第i个字符正好是ch，那么往相邻的格子寻找路径上的第i+1个字符。除在矩阵边
// 界上的格子之外，其他格子都有4个相邻的格子。重复这个过程直到路径上的所有字符都
// 在矩阵中找到相应的位置。
//   由于回朔法的递归特性，路径可以被开成一个栈。当在矩阵中定位了路径中前n个字符
// 的位置之后，在与第n个字符对应的格子的周围都没有找到第n+1个字符，这个时候只要
// 在路径上回到第n-1个字符，重新定位第n个字符。
//   由于路径不能重复进入矩阵的格子，还需要定义和字符矩阵大小一样的布尔值矩阵，
// 用来标识路径是否已经进入每个格子。 当矩阵中坐标为（row,col）的格子和路径字符串
// 中相应的字符一样时，从4个相邻的格子(row,col-1),(row-1,col),(row,col+1)以及(row+1,col)
// 中去定位路径字符串中下一个字符。
// 如果4个相邻的格子都没有匹配字符串中下一个的字符，表明当前路径字符串中字符在矩阵
// 中的定位不正确，我们需要回到前一个，然后重新定位。
// 一直重复这个过程，直到路径字符串上所有字符都在矩阵中找到合适的位置

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{  
		if(str==NULL||rows<=0||cols<=0){
			return false;
		}
		bool *isOk=new bool[rows*cols](); // 创建一个和matrix等尺寸的bool数组
		for(int i=0;i<rows;i++){ // 遍历matrix的每个位置，从每个位置出发，进行路径的搜索
			for(int j=0;j<cols;j++){
				if(isHsaPath(matrix,rows,cols,str,isOk,i,j)){
					return true;
				}
			}
		}
		return false;
	}

	bool isHsaPath(char *matrix,int rows,int cols,char *str,bool *isOk,int curx,int cury)
	{
		if(*str=='\0'){ // 当目标路径已经搜索完，返回true
			return true;
		}
		if(cury==cols){ // 因为题目用一个一维的数组模拟二维数组，所以当cury=cols时，代表要换到下一行的首元素了
			curx++;
			cury=0;
		}
		if(cury==-1){ // 同理，当cury=-1时，代表要换到上一行的尾元素了
			curx--;
			cury=cols-1;
		}
		if(curx<0||curx>=rows){ // 当行出界了，返回false
			return false;
		}
		// 若这个位置已经被搜索过，且属于路径；或者该位置不等于目标路径的对应字符，返回false
		if(isOk[curx*cols+cury]||*str!=matrix[curx*cols+cury]){
			return false;
		}
		// 否则，令该位置为“搜索过，属于路径”
		isOk[curx*cols+cury]=true;
		bool sign=isHsaPath(matrix,rows,cols,str+1,isOk,curx-1,cury) // 对该位置的上下左右进行递归，搜索str的下一个字符
			||isHsaPath(matrix,rows,cols,str+1,isOk,curx+1,cury)
			||isHsaPath(matrix,rows,cols,str+1,isOk,curx,cury-1)
			||isHsaPath(matrix,rows,cols,str+1,isOk,curx,cury+1);
		isOk[curx*cols+cury]=false; // 如果前后左右都走不通的话，则不能访问当前位置，但是当前这个节点后期还有可能用到，需要回溯到上一层，所以设置回false
		return sign;
	}
};

