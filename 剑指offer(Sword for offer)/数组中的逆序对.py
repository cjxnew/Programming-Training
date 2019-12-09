# 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
# 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
# 即输出P%1000000007

# 用稍稍修改的归并排序来做
# 具体思路看本题的cpp版本
class Solution:
    def InversePairs(self, data):
        # write code here
        if len(data) <= 1:
            return 0
        global count
        count = 0
        self.mergeSort(data, 0, len(data)-1)
        return count % 1000000007
    
    # 归并排序
    def mergeSort(self, data, L, R):
        if L < R:
            mid = int((L+R)/2)
            self.mergeSort(data, L, mid)
            self.mergeSort(data, mid+1, R)
            self.merge(data, L, R)
            
    # 合并操作
    def merge(self, data, L, R):
        mid = int((L+R)/2)
        help = [0]*(R-L+1)
        p1, p2, i = mid, R, R-L
        global count
        while p1 >= L and p2 >= mid+1: # 从后往前比较两段数据
            if data[p1] > data[p2]:
                help[i] = data[p1]
                i, p1 = i-1, p1-1
                count += p2 - mid
            else:
                help[i] = data[p2]
                i, p2 = i-1, p2-1
        while p1 >= L:
            help[i] = data[p1]
            i, p1 = i-1, p1-1
        while p2 >= mid+1:
            help[i] = data[p2]
            i, p2 = i-1, p2-1
        data[L:R+1] = help[:]
        
