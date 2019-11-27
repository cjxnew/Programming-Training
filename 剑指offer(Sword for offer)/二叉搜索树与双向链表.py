# 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 我的方法。先中序遍历这棵树，得到升序排列的结点序列，再将这些结点的左右指针连起来
class Solution:
    def Convert(self, root):
        # write code here
        if root == None:
            return None
        # 保存搜索树的中序遍历结点序列
        inNodeList = []
        # 中序遍历root树，将结点按中序遍历（升序）放到inNodeList里
        self.InOrder(root, inNodeList)
        # 遍历升序结点，连成双向链表，left指向小值结点，right指向大值结点
        for index in range(len(inNodeList)):
            if index != 0:
                inNodeList[index].left = inNodeList[index-1]
            if index != len(inNodeList)-1:
                inNodeList[index].right = inNodeList[index+1]
        return inNodeList[0]
        
    def InOrder(self, root, inNodeList):
        if(root != None):
            self.InOrder(root.left, inNodeList)
            inNodeList.append(root)
            self.InOrder(root.right, inNodeList)
