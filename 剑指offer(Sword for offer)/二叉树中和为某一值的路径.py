# 经典方法。思路和我的差不多，但比我优雅多了。
# 其实这一题就是引出所有的从根结点到叶子结点的路径的变形，就在判断条件上多了一个 sum(path) == self.sums。所以，解法如下：

# 方法一：递归
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
 
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        result = []
        if root == None:
            return result
        self.sums = expectNumber
        self.DFS(root, result, [root.val])
        result.sort(key = lambda i:len(i),reverse=True)
        return result
 
    def DFS(self, root, result, path):
        if root.left == None and root.right == None and sum(path) == self.sums:
            result.append(path)
        if root.left != None:
            self.DFS(root.left, result, path+[root.left.val])
        if root.right != None:
            self.DFS(root.right, result, path + [root.right.val])
            
# 方法二：非递归解法
class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None
 
class Solution2:
    def binaryTreePaths2(self, root):
        if root == None:
            return []
        result = []
        stack = []
        stack.append((root, [root.val]))
        while stack:
            node, path = stack.pop()
            if node.left == None and node.right == None:
                result.append(path)
            if node.left != None:
                stack.append((node.left, path + [node.left.val]))
            if node.right != None:
                stack.append((node.right, path + [node.right.val]))
        result.sort(key = lambda i:len(i),reverse=True)
        return result
        
