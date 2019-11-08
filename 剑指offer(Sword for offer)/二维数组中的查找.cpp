// 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
      if(array.empty() || (*(array.begin())).empty()){return false;}
      int min_num = *((*(array.begin())).begin());
      int max_num = *((*(array.end() - 1)).end() - 1);
      if(target < min_num || target > max_num){return false;}
      for(vector<vector<int> >::iterator a_row_iter = array.begin(); a_row_iter != array.end(); a_row_iter++){
        if(target >= *((*a_row_iter).begin()) && target <= *((*a_row_iter).end() - 1)){
          vector<int>::iterator find_index = find((*a_row_iter).begin(), (*a_row_iter).end(), target);
          if(find_index != (*a_row_iter).end()){return true;}
        }
      }
      return false;
    }
};
